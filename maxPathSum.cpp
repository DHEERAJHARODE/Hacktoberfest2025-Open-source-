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
    // Edge Case \U0001f62d\U0001f62d
    // if negative comes use max (0,val) to only consider 0 as -ve value for max num
private:
    int solve(TreeNode* root, int &maxSum){
        // Base Case
        if(root == NULL){
            return 0;
        }

        int left = max(0,solve(root -> left, maxSum));      // negatives ki jgah 0 lelo
        int right = max(0,solve(root -> right, maxSum));

        int sum = left + right + root -> val;
        maxSum = max(sum,maxSum);

        int ans = max(left,right) + root -> val;
        return ans;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        solve(root, maxSum);
        return maxSum;
    }
};
