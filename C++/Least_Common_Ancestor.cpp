#include <bits/stdc++.h>
using namespace std;

// A Binary Tree node
struct Node{
	int key;
	struct Node *left, *right;
};

Node * newNode(int k){
// function to create new node using the key
	Node *temp = new Node;
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

// storing paths in a vector of bool
bool findPath(Node *root, vector<int> &path, int k){
	// base case
	if (root == NULL) return false;

	path.push_back(root->key);

	// See if the k is same as root's key
	if (root->key == k)
		return true;

	// Check if k is found in left or right sub-tree
	if ( (root->left && findPath(root->left, path, k)) ||
		(root->right && findPath(root->right, path, k)) )
		return true;

	// If not present in subtree rooted with root, remove root from
	// path[] and return false
	path.pop_back();
	return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree, otherwise return -1
int findLCA(Node *root, int n1, int n2){
	vector<int> path1, path2;

	if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	// Compare the paths to get the first different value 
	int i;
	for (i = 0; i < path1.size() && i < path2.size() ; i++)
		if (path1[i] != path2[i])
			break;
	return path1[i-1];
}

// Driver program to test above functions
int main(){
    /*****************
     *  Driver program just to verify and run the LCA function
     * It can be implimented on personal use case
    ***************/
    
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "lca(5, 4) = " << findLCA(root, 5, 4)<<endl;
    cout << "lca(4, 3) = " << findLCA(root, 4, 3)<<endl;
    cout << "lca(2, 6) = " << findLCA(root, 2, 6)<<endl;
    cout << "lca(3, 4) = " << findLCA(root, 3, 4)<<endl;
    return 0;
}



// A O(n) solution to find LCA of two given values n1 and n2
