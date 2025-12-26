#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->priority = rand();
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

struct Node* insert(struct Node* root, int key) {
    if (!root) return createNode(key);

    if (key <= root->key) {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority)
            root = rotateRight(root);
    } else {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority)
            root = rotateLeft(root);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("(%d, %d) ", root->key, root->priority);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    srand(time(NULL));

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the treap:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
