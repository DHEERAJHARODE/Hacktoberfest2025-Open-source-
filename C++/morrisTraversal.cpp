#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *right, *left;
  Node(int x) {
    this->data = x;
    this->left = nullptr;
    this->right = NULL;
  }
};
void inorder(Node *root) {
  if (root) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}
void preorder(Node *root) {
  if (root) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
//Inorder-Morris Traversal
void morrisI(Node *root) {
  while (root != NULL) {
    if (!root->left) {
      cout << root->data << " ";
      root = root->right;
    } else {
      Node *temp = root->left;
      while (temp->right and temp->right != root) {
        temp = temp->right;
      }
      if (temp->right == root) {
        temp->right = NULL;
        cout << root->data << " ";
        root = root->right;
      } else {
        temp->right = root;
        root = root->left;
      }
    }
  }
}
//preorder-Morris Traversal
void morrisP(Node *root){
   while(root){
     if(!root->left){
       cout<<root->data<<" ";
       root=root->right;
     }
     else{
          Node *t=root->left;
          while(t->right and t->right!=root){
            t=t->right;
          }
         if(t->right==root){
           t->right=NULL;
           root=root->right;
         }
         else{
           cout<<root->data<<" ";
           t->right=root;
           root=root->left;
         }
     }
   }
}
Node *create(Node *root) {
  int n;
  cout << "enter value:" << endl;
  cin >> n;
  if (n == -1) {
    return NULL;
  }
  root = new Node(n);
  root->left = create(root->left);
  root->right = create(root->right);
  return root;
}
int main() {
  Node *root = create(root);
  // preorder(root);
  cout << endl;
  morrisP(root);
}
