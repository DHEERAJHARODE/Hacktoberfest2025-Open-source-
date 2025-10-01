// tiny_compiler.c
// A small educational compiler + VM for a tiny language.
// Build: gcc -std=c11 -O2 -o tiny_compiler tiny_compiler.c
// Run: ./tiny_compiler program.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ---------------------------
   Lexer
   --------------------------- */
typedef enum {
    T_EOF, T_NUMBER, T_IDENT,
    T_PLUS, T_MINUS, T_STAR, T_SLASH,
    T_LPAREN, T_RPAREN,
    T_SEMI, T_ASSIGN, // ; and =
    T_LET, T_PRINT,
    T_INVALID
} TokenType;

typedef struct {
    TokenType type;
    char *text;     // for identifiers or numbers (null-terminated)
    long value;     // numeric value if number
} Token;

typedef struct {
    const char *src;
    size_t pos;
} Lexer;

void lexer_init(Lexer *lx, const char *s) { lx->src = s; lx->pos = 0; }

static void token_free(Token *t) {
    if (t->text) { free(t->text); t->text = NULL; }
}

static int is_ident_start(char c) { return isalpha((unsigned char)c) || c == '_'; }
static int is_ident_part(char c)  { return isalnum((unsigned char)c) || c == '_'; }

Token lexer_next(Lexer *lx) {
    const char *s = lx->src;
    size_t p = lx->pos;
    while (s[p] && isspace((unsigned char)s[p])) p++;
    if (!s[p]) { lx->pos = p; return (Token){T_EOF, NULL, 0}; }

    char c = s[p];
    if (isdigit((unsigned char)c)) {
        size_t start = p;
        long val = 0;
        while (s[p] && isdigit((unsigned char)s[p])) {
            val = val * 10 + (s[p] - '0');
            p++;
        }
        lx->pos = p;
        Token t = {T_NUMBER, NULL, val};
        return t;
    }
    if (is_ident_start(c)) {
        size_t start = p;
        while (s[p] && is_ident_part(s[p])) p++;
        size_t len = p - start;
        char *ident = malloc(len + 1);
        memcpy(ident, s + start, len);
        ident[len] = '\0';
        lx->pos = p;
        if (strcmp(ident, "let") == 0) { free(ident); return (Token){T_LET, NULL, 0}; }
        if (strcmp(ident, "print") == 0) { free(ident); return (Token){T_PRINT, NULL, 0}; }
        return (Token){T_IDENT, ident, 0};
    }

    lx->pos = p+1;
    switch (c) {
        case '+': return (Token){T_PLUS, NULL, 0};
        case '-': return (Token){T_MINUS, NULL, 0};
        case '*': return (Token){T_STAR, NULL, 0};
        case '/': return (Token){T_SLASH, NULL, 0};
        case '(' : return (Token){T_LPAREN, NULL, 0};
        case ')' : return (Token){T_RPAREN, NULL, 0};
        case ';' : return (Token){T_SEMI, NULL, 0};
        case '=' : return (Token){T_ASSIGN, NULL, 0};
        default: return (Token){T_INVALID, NULL, 0};
    }
}

/* ---------------------------
   Parser & AST
   --------------------------- */

typedef enum { NODE_NUM, NODE_VAR, NODE_BINOP } NodeKind;

typedef struct Node {
    NodeKind kind;
    long value;            // for number
    char *name;            // for variable
    int op;                // for binop: '+','-','*','/'
    struct Node *left, *right;
} Node;

Node *node_num(long v) {
    Node *n = malloc(sizeof(Node)); memset(n,0,sizeof(Node));
    n->kind = NODE_NUM; n->value = v; return n;
}
Node *node_var(const char *name) {
    Node *n = malloc(sizeof(Node)); memset(n,0,sizeof(Node));
    n->kind = NODE_VAR; n->name = strdup(name); return n;
}
Node *node_binop(int op, Node *l, Node *r) {
    Node *n = malloc(sizeof(Node)); memset(n,0,sizeof(Node));
    n->kind = NODE_BINOP; n->op = op; n->left = l; n->right = r; return n;
}
void node_free(Node *n) {
    if (!n) return;
    if (n->kind == NODE_VAR && n->name) free(n->name);
    node_free(n->left); node_free(n->right);
    free(n);
}

/* Statements */
typedef enum { STMT_LET, STMT_PRINT } StmtKind;
typedef struct Stmt {
    StmtKind kind;
    char *name;  // for let
    Node *expr;
    struct Stmt *next;
} Stmt;

Stmt *stmt_let(const char *name, Node *expr) {
    Stmt *s = malloc(sizeof(Stmt)); memset(s,0,sizeof(Stmt));
    s->kind = STMT_LET; s->name = strdup(name); s->expr = expr; s->next = NULL; return s;
}
Stmt *stmt_print(Node *expr) {
    Stmt *s = malloc(sizeof(Stmt)); memset(s,0,sizeof(Stmt));
    s->kind = STMT_PRINT; s->name = NULL; s->expr = expr; s->next = NULL; return s;
}
void stmt_free_all(Stmt *head) {
    while (head) {
        Stmt *n = head->next;
        if (head->name) free(head->name);
        node_free(head->expr);
        free(head);
        head = n;
    }
}

/* Parser state */
typedef struct {
    Lexer lx;
    Token cur;
} Parser;

void parser_init(Parser *p, const char *s) {
    lexer_init(&p->lx, s);
    p->cur = lexer_next(&p->lx);
}

void advance(Parser *p) {
    token_free(&p->cur);
    p->cur = lexer_next(&p->lx);
}

int accept(Parser *p, TokenType t) {
    if (p->cur.type == t) { advance(p); return 1; }
    return 0;
}
int expect(Parser *p, TokenType t, const char *errmsg) {
    if (p->cur.type == t) { advance(p); return 1; }
    fprintf(stderr, "Parse error: expected %s\n", errmsg);
    exit(1);
}

/* Forward declarations */
Node *parse_expr(Parser *p);

Node *parse_factor(Parser *p) {
    if (p->cur.type == T_NUMBER) {
        long v = p->cur.value;
        advance(p);
        return node_num(v);
    }
    if (p->cur.type == T_IDENT) {
        char *name = strdup(p->cur.text);
        advance(p);
        Node *n = node_var(name);
        free(name);
        return n;
    }
    if (accept(p, T_LPAREN)) {
        Node *e = parse_expr(p);
        expect(p, T_RPAREN, "')'");
        return e;
    }
    fprintf(stderr, "Parse error: unexpected token in factor\n"); exit(1);
}

Node *parse_term(Parser *p) {
    Node *node = parse_factor(p);
    while (p->cur.type == T_STAR || p->cur.type == T_SLASH) {
        int op = (p->cur.type == T_STAR) ? '*' : '/';
        advance(p);
        Node *r = parse_factor(p);
        node = node_binop(op, node, r);
    }
    return node;
}

Node *parse_expr(Parser *p) {
    Node *node = parse_term(p);
    while (p->cur.type == T_PLUS || p->cur.type == T_MINUS) {
        int op = (p->cur.type == T_PLUS) ? '+' : '-';
        advance(p);
        Node *r = parse_term(p);
        node = node_binop(op, node, r);
    }
    return node;
}

/* parse statements: program -> stmt* EOF */
Stmt *parse_program(Parser *p) {
    Stmt *head = NULL, *tail = NULL;
    while (p->cur.type != T_EOF) {
        if (p->cur.type == T_LET) {
            advance(p);
            if (p->cur.type != T_IDENT) { fprintf(stderr,"expected identifier after let\n"); exit(1);}
            char *name = strdup(p->cur.text);
            advance(p);
            expect(p, T_ASSIGN, "'='");
            Node *expr = parse_expr(p);
            expect(p, T_SEMI, "';'");
            Stmt *s = stmt_let(name, expr);
            free(name);
            if (!head) head = tail = s; else { tail->next = s; tail = s; }
        } else if (p->cur.type == T_PRINT) {
            advance(p);
            Node *expr = parse_expr(p);
            expect(p, T_SEMI, "';'");
            Stmt *s = stmt_print(expr);
            if (!head) head = tail = s; else { tail->next = s; tail = s; }
        } else {
            fprintf(stderr, "Parse error: expected 'let' or 'print'\n");
            exit(1);
        }
    }
    return head;
}

/* ---------------------------
   Symbol table for variables
   --------------------------- */

typedef struct {
    char **names;
    int count, cap;
} SymTab;

void symtab_init(SymTab *t) { t->names = NULL; t->count = t->cap = 0; }
int symtab_find(SymTab *t, const char *name) {
    for (int i = 0; i < t->count; ++i) if (strcmp(t->names[i], name) == 0) return i;
    return -1;
}
int symtab_add(SymTab *t, const char *name) {
    int idx = symtab_find(t, name);
    if (idx >= 0) return idx;
    if (t->count == t->cap) {
        t->cap = (t->cap == 0) ? 8 : t->cap * 2;
        t->names = realloc(t->names, sizeof(char*) * t->cap);
    }
    t->names[t->count] = strdup(name);
    return t->count++;
}
void symtab_free(SymTab *t) {
    for (int i = 0; i < t->count; ++i) free(t->names[i]);
    free(t->names);
}

/* ---------------------------
   Bytecode definitions
   --------------------------- */

typedef enum {
    OP_ICONST, // push constant: operand = constant index in const_pool
    OP_ADD, OP_SUB, OP_MUL, OP_DIV,
    OP_LOAD, // load variable index
    OP_STORE, // store variable index
    OP_PRINT,
    OP_HALT
} OpCode;

typedef struct {
    OpCode *code;
    int *arg; // parallel array: one int per opcode (unused ops set to 0)
    int len, cap;
    long *const_pool;
    int const_len, const_cap;
} Bytecode;

void bc_init(Bytecode *b) {
    b->code = NULL; b->arg = NULL; b->len = b->cap = 0;
    b->const_pool = NULL; b->const_len = b->const_cap = 0;
}
void bc_push_inst(Bytecode *b, OpCode op, int operand) {
    if (b->len == b->cap) {
        b->cap = (b->cap==0) ? 64 : b->cap * 2;
        b->code = realloc(b->code, sizeof(OpCode) * b->cap);
        b->arg  = realloc(b->arg, sizeof(int) * b->cap);
    }
    b->code[b->len] = op;
    b->arg[b->len] = operand;
    b->len++;
}
int bc_add_const(Bytecode *b, long v) {
    for (int i = 0; i < b->const_len; ++i) if (b->const_pool[i] == v) return i;
    if (b->const_len == b->const_cap) {
        b->const_cap = (b->const_cap==0) ? 16 : b->const_cap*2;
        b->const_pool = realloc(b->const_pool, sizeof(long)*b->const_cap);
    }
    b->const_pool[b->const_len] = v;
    return b->const_len++;
}
void bc_free(Bytecode *b) {
    free(b->code); free(b->arg); free(b->const_pool);
}

/* ---------------------------
   Code generation: AST -> bytecode
   --------------------------- */

void gen_expr(Bytecode *bc, SymTab *st, Node *n);

void gen_node_number(Bytecode *bc, Node *n) {
    int idx = bc_add_const(bc, n->value);
    bc_push_inst(bc, OP_ICONST, idx);
}
void gen_node_var(Bytecode *bc, SymTab *st, Node *n) {
    int idx = symtab_find(st, n->name);
    if (idx < 0) { fprintf(stderr, "Undefined variable: %s\n", n->name); exit(1); }
    bc_push_inst(bc, OP_LOAD, idx);
}
void gen_node_binop(Bytecode *bc, SymTab *st, Node *n) {
    gen_expr(bc, st, n->left);
    gen_expr(bc, st, n->right);
    switch (n->op) {
        case '+': bc_push_inst(bc, OP_ADD, 0); break;
        case '-': bc_push_inst(bc, OP_SUB, 0); break;
        case '*': bc_push_inst(bc, OP_MUL, 0); break;
        case '/': bc_push_inst(bc, OP_DIV, 0); break;
        default: fprintf(stderr, "Unknown binary op\n"); exit(1);
    }
}

void gen_expr(Bytecode *bc, SymTab *st, Node *n) {
    if (!n) return;
    if (n->kind == NODE_NUM) gen_node_number(bc, n);
    else if (n->kind == NODE_VAR) gen_node_var(bc, st, n);
    else if (n->kind == NODE_BINOP) gen_node_binop(bc, st, n);
}

/* program codegen */
void gen_program(Bytecode *bc, SymTab *st, Stmt *prog) {
    for (Stmt *s = prog; s; s = s->next) {
        if (s->kind == STMT_LET) {
            int idx = symtab_add(st, s->name);
            gen_expr(bc, st, s->expr);
            bc_push_inst(bc, OP_STORE, idx);
        } else if (s->kind == STMT_PRINT) {
            gen_expr(bc, st, s->expr);
            bc_push_inst(bc, OP_PRINT, 0);
        }
    }
    bc_push_inst(bc, OP_HALT, 0);
}

/* ---------------------------
   Virtual Machine
   --------------------------- */
typedef struct {
    long *stack; int sp, stack_cap;
    long *vars; int var_count;
    Bytecode *bc;
} VM;

void vm_init(VM *vm, Bytecode *bc, int var_count) {
    vm->stack = malloc(sizeof(long) * 1024);
    vm->sp = 0; vm->stack_cap = 1024;
    vm->vars = calloc(var_count, sizeof(long));
    vm->var_count = var_count;
    vm->bc = bc;
}
void vm_push(VM *vm, long v) {
    if (vm->sp == vm->stack_cap) {
        vm->stack_cap *= 2; vm->stack = realloc(vm->stack, sizeof(long)*vm->stack_cap);
    }
    vm->stack[vm->sp++] = v;
}
long vm_pop(VM *vm) {
    if (vm->sp == 0) { fprintf(stderr, "Runtime stack underflow\n"); exit(1); }
    return vm->stack[--vm->sp];
}
void vm_run(VM *vm) {
    Bytecode *b = vm->bc;
    int ip = 0;
    while (ip < b->len) {
        OpCode op = b->code[ip];
        int arg = b->arg[ip];
        switch (op) {
            case OP_ICONST:
                vm_push(vm, b->const_pool[arg]);
                break;
            case OP_ADD: {
                long r = vm_pop(vm); long l = vm_pop(vm); vm_push(vm, l + r);
                break;
            }
            case OP_SUB: {
                long r = vm_pop(vm); long l = vm_pop(vm); vm_push(vm, l - r);
                break;
            }
            case OP_MUL: {
                long r = vm_pop(vm); long l = vm_pop(vm); vm_push(vm, l * r);
                break;
            }
            case OP_DIV: {
                long r = vm_pop(vm); long l = vm_pop(vm);
                if (r == 0) { fprintf(stderr, "Division by zero\n"); exit(1); }
                vm_push(vm, l / r);
                break;
            }
            case OP_LOAD:
                if (arg < 0 || arg >= vm->var_count) { fprintf(stderr,"bad var idx\n"); exit(1);}
                vm_push(vm, vm->vars[arg]);
                break;
            case OP_STORE:
                if (arg < 0 || arg >= vm->var_count) { fprintf(stderr,"bad var idx\n"); exit(1);}
                vm->vars[arg] = vm_pop(vm);
                break;
            case OP_PRINT: {
                long v = vm_pop(vm);
                printf("%ld\n", v);
                break;
            }
            case OP_HALT:
                return;
            default:
                fprintf(stderr, "Unknown opcode %d\n", op); exit(1);
        }
        ip++;
    }
}

/* ---------------------------
   Utility: read file
   --------------------------- */
char *read_file(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) { perror("open"); return NULL; }
    fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
    char *buf = malloc(sz + 1);
    if (fread(buf, 1, sz, f) != (size_t)sz) { perror("read"); free(buf); fclose(f); return NULL; }
    buf[sz] = '\0'; fclose(f); return buf;
}

/* ---------------------------
   Main
   --------------------------- */

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s program.txt\n", argv[0]);
        fprintf(stderr, "Example program:\n"
                "let x = 2 + 3 * (4 + 1);\n"
                "print x;\n"
                "print x + 10;\n");
        return 1;
    }

    char *source = read_file(argv[1]);
    if (!source) return 1;

    Parser parser;
    parser_init(&parser, source);
    Stmt *prog = parse_program(&parser);
    token_free(&parser.cur);

    Bytecode bc; bc_init(&bc);
    SymTab st; symtab_init(&st);

    gen_program(&bc, &st, prog);

    VM vm; vm_init(&vm, &bc, st.count);
    vm_run(&vm);

    // cleanup
    free(source);
    stmt_free_all(prog);
    bc_free(&bc);
    symtab_free(&st);
    free(vm.stack);
    free(vm.vars);
    return 0;
}
