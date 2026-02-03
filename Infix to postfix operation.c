#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct 
{
    struct Node *top;
}Stack;
int IsEmpty(Stack s);
int push(Stack *s,int v);
int pop(Stack *s,struct Node **v);
void display(Stack s,int a,int n);
int IsOperand(int c);
int getVal(char a);
int IsLtoH(char a,char b);
int Infix_Postfix(char *inp , char *out);
struct Node *m;
int main()
{
    char inp[100];
    int l=0,i=0;
    printf("Enter infix expression:");
    gets(inp);
    while(inp[l] != '\0')
    {
        l++;
    }
    char out[l];
    printf("The postfix Expression is:");
    int c=Infix_Postfix(inp,out);
    while(out[i]!='\0')
    {
        printf("%c",out[i]);
        i++;
    }
    return 0;
}
int Infix_Postfix(char *inp , char *out)
{
    Stack s;
    s.top=NULL; 
    int i=0,k=0,p,q;
    while(inp[i] != '\0')
    {
        if(IsOperand(inp[i]))
        {
            out[k++]=inp[i];
        }
        else if(inp[i]==32)
        {
            i++;
            continue;
        }
        else if(inp[i]=='(')
        {
            q=push(&s,inp[i]);
        }
        else if(inp[i]==')')
        {
            while(1>0)
            {
                p=pop(&s,&m);
                if(p==1)
                {
                    printf("Improper bracket pairs\n");
                    return 1;
                }
                if(m->data=='(')
                    break;
                out[k++]=m->data;
            }
        }
        else
        {
            if(IsEmpty(s))
            {
                q=push(&s,inp[i]);                
            }
            else 
            {
                p=pop(&s,&m);
                if(p==1)
                {
                    printf("Improper bracket pairs\n");
                    return 1;
                }
                if((m->data=='(')||(IsLtoH(m->data,inp[i])))
                {
                    push(&s,m->data);
                    push(&s,inp[i]);
                }
                else
                {
                    out[k++]=m->data;
                    i--;
                }
                
            }
        }
        i++;
    }
    while(!(IsEmpty(s)))
    {
        p=pop(&s,&m);
        if(p==1)
        {
            printf("Improper bracket pairs\n");
            return 1;
        }
        out[k++]=m->data;
    }
    out[k]='\0';
}
int IsLtoH(char a,char b)
{
    if(getVal(a)<getVal(b))
        return 1;
    else 
        return 0;
}
int getVal(char a)
{
    int t;
    switch(a)
    {
        case '+':
        case '-': t=1;
                break;
        case '*':
        case '/':t=2;
                break;
        case '^':t=3;
                break;
    }
    return t;
}
int IsOperand(int c)
{
    if( ((c>=65)&&(c<=90)) || ((c>=97)&&(c<=122)) )
    {
        return 1;
    }
    return 0;
}
int IsEmpty(Stack s)
{
    if(s.top==NULL)
        return 1;
    return 0;
}
int push(Stack *s,int v)
{
    struct Node *cur;
    cur= (struct Node *)malloc(sizeof(struct Node));
    if(cur==NULL)
    {
        printf("Overflow");
        return 1;
    }
    cur->data=v;
    cur->next = s->top;
    s->top=cur;
    return 0;
}
int pop(Stack *s,struct Node **v)
{
    if(IsEmpty(*s))
    {
        printf("Underflow");
        return 1;
    }
    *v = s->top;
    s->top=s->top->next;
    return 0;
}
void display(Stack s,int a,int n)
{
    Stack s1;
    s1.top=NULL;
    int k,l;
    while(!(IsEmpty(s)))
    {
        k=pop(&s,&m);
        if(a==1)
            printf("%d\t",m->data);
        l=push(&s1,m->data);
    }
    while(!(IsEmpty(s1)))
    {
        k=pop(&s1,&m);
        if(a==0)
            printf("%d\t",m->data);
        l=push(&s,m->data);
    }
}
