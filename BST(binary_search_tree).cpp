#include<iostream>
using namespace std;

struct b_tree{
	int data;
	struct b_tree *left;
	struct b_tree *right;
	b_tree(int key_data)
	{
		data = key_data;
		left = right = NULL;
	}
};
typedef struct b_tree node;
node* search(node *root,int key)
{
	if(root == NULL || root->data == key)
	{
		return root;
	}
	if(root->data < key)
	{
		return search(root->right,key);
	}
	return search(root->left,key);
}
void print_binary_search(node *root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<endl;
	print_binary_search(root->left);
	print_binary_search(root->right);
}
int main()
{
	int key;
	node *root = new node(50);
	root->left = new node(34);
	root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);
	print_binary_search(root);
    cout<<"Enter the key value you want to find in the tree: ";
    cin>>key;
    (search(root ,key) != NULL) ? cout<<"Found\n":
    	cout<<"Not Found\n";
    
	
}
