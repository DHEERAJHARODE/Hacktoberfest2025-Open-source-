#include <stdio.h>
#include <stdlib.h>

struct node {                   //creating node of a tree with a val, right child poitner and a left child poitner
   int val; 	
   struct node *left;
   struct node *right;
};

struct node *root = NULL;              //defining root of the tree

void insert(int val) {                  //insertion operation in the binary tree
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   struct node *curr;
   struct node *parent;
   temp->val = val;
   temp->left = NULL;
   temp->right = NULL;
   if(root == NULL) {
      root = temp;
   } else {
      curr = root;
      parent = NULL;
      while(1) { 
         parent = curr;
         if(val < parent->val) {
            curr = curr->left;
            if(curr == NULL) {
               parent->left = temp;
               return;
            }
         }
         else {
            curr = curr->right;
            if(curr == NULL) {
               parent->right = temp;
               return;
            }
         }
      }            
   }
}

void preOrder(struct node* root) {              //preorder traversal: root->left child->right-child
   if(root != NULL) {
      printf("%d ",root->val);
      preOrder(root->left);
      preOrder(root->right);
   }
}

void inOrder(struct node* root) {               //inOrder traversal: left child-> root->right child
   if(root != NULL) {
      inOrder(root->left);
      printf("%d ",root->val);          
      inOrder(root->right);
   }
}

void postOrder(struct node* root) {             //postoder traversal: left child->right child->root
   if(root != NULL) {
      postOrder(root->left);
      postOrder(root->right);
      printf("%d ", root->val);
   }
}

int main() {

int size=10;
   int arr[size] = { 1,3,5,7,2,4,6,8,9,10 };

   for(int i = 0; i < size; i++)
      insert(arr[i]);

       printf("\nInorder traversal of the tree: ");
   inOrder(root);

   printf("\nPreorder traversal of the tree: ");
   preOrder(root);



   printf("\nPost order traversal of the tree: ");
   postOrder(root);       

   return 0;
}
