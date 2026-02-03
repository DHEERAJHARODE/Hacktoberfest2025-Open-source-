// BST TO Min Heap



// Header Files
#include<bits/stdc++.h>
using namespace std;
 
//Storing Binary Tree
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
Node* insert(Node* root, int key)
{
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
    return root;
}
 
//Level order traversal
void LevelOrderTraversal(Node* root)
{
    if (root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node* front = q.front();
            q.pop();
            cout << front->data << ' ';
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}
 
//Inorder traversal
void inorder(Node* root, queue<int> &key)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left, key);
    key.push(root->data);
    inorder(root->right, key);
}
 
//Preorder Traversal
void preorder(Node* root, queue<int> &key)
{
    if (root == nullptr) {
        return;
    }
    root->data = key.front();
    key.pop();
    preorder(root->left, key);
    preorder(root->right, key);
}
 
//Converting BST into  min Heap
void convert(Node* root)
{
    if (root == nullptr) {
        return;
    }
    queue<int> key;
    inorder(root, key);
    preorder(root, key);
}
 
int main()
{
    vector<int> key = { 5, 3, 2, 4, 8, 6, 10 }; 
    Node* root = nullptr;
    for (int k: key) {
        root = insert(root, k);
    }
    convert(root);
    LevelOrderTraversal(root);
 
    return 0;
}


/*Output:

2
3 6
4 5 8 10

Time Complexity: O(n)<br>
Space Complexity: O(n)
*/
