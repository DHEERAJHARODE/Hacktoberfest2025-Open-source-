#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


// insert values into BST
Node* insertBST(Node* &root,int data){
    // base case
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(root->data < data){
        root->right= insertBST(root->right,data);
    }
    else{
        root->left = insertBST(root->left,data);
    }
    return root;
}



// Taking Input from User!
void takenInput(Node* &root){
    cout<<"Enter the value to create BST "<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        root = insertBST(root,data);
        cin>>data;
    }
}

// traverse BST by a level order 
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if (temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


// MAIN FUNCTION OF CODE
int main()
{
    Node* root = NULL;
    takenInput(root);
    cout<<"Print BST\n";
    levelOrderTraversal(root);
    return 0;
}
