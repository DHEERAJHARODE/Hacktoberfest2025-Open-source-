/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* ConstructBST(vector<int>& preorder,int &i,int max,int min)
    {
        if(i>=preorder.size())
        {
            return NULL;
        }
        
        if(preorder[i]>max || preorder[i]<min)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        
        root->left = ConstructBST(preorder,i,root->val,min);
        root->right = ConstructBST(preorder,i,max,root->val);
        
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
       int min = INT_MIN;
       int max = INT_MAX;
        int i = 0;
        
        return ConstructBST(preorder,i,max,min);
    }
};