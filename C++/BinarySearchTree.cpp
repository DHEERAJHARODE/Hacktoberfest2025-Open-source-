#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node*left;
		Node*right;
		
		Node(int d){
			this->data=d;
			this->left=NULL;
			this->right=NULL;
		}
		
		
};

void inorder(Node*&root){
	if(root==NULL){
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node*&root){
	if(root==NULL){
		return;
	}
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

Node*insertIntoBST(Node*root,int d){
	//base case
	if(root==NULL){
		root=new Node(d);
		return root;
	}
	
	//right mai dala 
	if(d>root->data){
		root->right=insertIntoBST(root->right,d);
	}
	
	//left mai dala
	else{
		root->left=insertIntoBST(root->left,d);
	}
	
	return root;
}

bool SearchNode(Node*&root, int target){
	
	//base case
	if(root==NULL  ){
		return false; 
	}
	
	if(root->data==target){
		return true;
	}
	
	else if(target<root->data){
		SearchNode(root->left, target);
	}
	else{
		SearchNode(root->right,target);
	}
	
	
}

Node*buildATree(Node*&root){
	cout<<"Enter the data\n";
	int data;
	cin>>data;
	while(data !=-1){
		root=insertIntoBST(root,data);
		cin>>data;
	}
}

int main(){
//	cout<<"Hello duniya";

Node*root=NULL;

cout<<"Building a treee"<<endl;
buildATree(root);

cout<<"Inorder traversal"<<endl;
inorder(root);

cout<<"Preorder traversal"<<endl;
preorder(root);
cout<<endl;
cout<<SearchNode(root, 5);

	return 0; 
}
