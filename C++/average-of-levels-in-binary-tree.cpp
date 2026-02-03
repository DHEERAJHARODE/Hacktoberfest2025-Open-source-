/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<TreeNode *> q;
        q.emplace_back(root);
        while (!q.empty()) {
            long long sum = 0, count = 0;
            vector<TreeNode *> next_q;
            for (const auto& n : q) {
                sum += n->val;
                ++count;
                if (n->left) {
                    next_q.emplace_back(n->left);
                }
                if (n->right) {
                    next_q.emplace_back(n->right);
                }
            }
            swap(q, next_q);
            result.emplace_back(sum * 1.0 / count);
        }
        return result;
    }
};
