#include <stdio.h>
#include <stdlib.h>

// Colors for Red-Black Tree nodes
enum Color { RED, BLACK };

// Structure for a Red-Black Tree node
struct Node {
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
};

// Root of the Red-Black Tree
struct Node* root = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

// Left rotation of node
void leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    
    if (y->left != NULL)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}

// Right rotation of node
void rightRotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    
    if (x->right != NULL)
        x->right->parent = y;
    
    x->parent = y->parent;
    
    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    
    x->right = y;
    y->parent = x;
}

// Fix Red-Black Tree violations after insertion
void fixViolation(struct Node* pt) {
    struct Node* parent_pt = NULL;
    struct Node* grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        // Case A: Parent of pt is left child of Grand-parent of pt
        if (parent_pt == grand_parent_pt->left) {
            struct Node* uncle_pt = grand_parent_pt->right;

            // Case 1: The uncle of pt is also red
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Case 2: pt is right child of its parent
                if (pt == parent_pt->right) {
                    leftRotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                // Case 3: pt is left child of its parent
                rightRotate(grand_parent_pt);
                enum Color temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        } else { // Case B: Parent of pt is right child of Grand-parent of pt
            struct Node* uncle_pt = grand_parent_pt->left;

            // Case 1: The uncle of pt is also red
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Case 2: pt is left child of its parent
                if (pt == parent_pt->left) {
                    rightRotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                // Case 3: pt is right child of its parent
                leftRotate(grand_parent_pt);
                enum Color temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Insert a new node with given data
void insert(int data) {
    struct Node* pt = createNode(data);

    // Do a normal BST insert
    if (root == NULL) {
        root = pt;
    } else {
        struct Node* current = root;
        struct Node* parent = NULL;
        
        while (current != NULL) {
            parent = current;
            if (pt->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        pt->parent = parent;
        
        if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;
    }

    // Fix Red-Black Tree violations
    fixViolation(pt);
}

// Inorder traversal of the tree
void inorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    
    inorderTraversal(node->left);
    printf("%d(%s) ", node->data, node->color == RED ? "RED" : "BLACK");
    inorderTraversal(node->right);
}

int main() {
    printf("Red-Black Tree Implementation\n");
    printf("============================\n\n");

    // Insert some values
    insert(7);
    insert(3);
    insert(18);
    insert(10);
    insert(22);
    insert(8);
    insert(11);
    insert(26);
    insert(2);
    insert(6);

    printf("Inorder traversal of the Red-Black Tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}