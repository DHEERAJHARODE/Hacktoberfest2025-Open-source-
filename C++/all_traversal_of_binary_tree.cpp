#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node (int value)
    {
        data = value;
        left = right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    if(root == NULL)
        return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
    }
}

void inorder(Node *root)          // left root right
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)        // root left right
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)      // left right root
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = new Node (5);
    root->left = new Node (10);
    root->right = new Node (15);
    root->left->left = new Node (20);
    root->left->right = new Node (25);
    root->right->right = new Node (30);

    inorder(root);
    cout << '\n';
    preorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    levelOrderTraversal(root);
    return 0;
}
