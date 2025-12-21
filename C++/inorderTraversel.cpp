#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 TreeNode * buildTreeRec(int s,int e,vector<int> inorderTraversel ){
     if(s>e){
         return NULL;
     }
     
     int ind = -1;
     int max = INT_MIN;
     for(int i=s;i<=e;i++){
         if(inorderTraversel[i]>max){
             max = inorderTraversel[i];
             ind = i;
         }
     }
     TreeNode *curr = new TreeNode(inorderTraversel[ind]);
     
     curr->left = buildTreeRec(s,ind-1,inorderTraversel);
     curr->right = buildTreeRec(ind+1,e,inorderTraversel);
     return curr;
     
 }
TreeNode* Solution::buildTree(vector<int> &A) {
    return buildTreeRec(0,A.size()-1,A);
    
}