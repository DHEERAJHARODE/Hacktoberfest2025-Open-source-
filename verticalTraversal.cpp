class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* temp = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(temp->val);

            if(temp->left) q.push({temp->left, {x-1, y+1}});
            if(temp->right) q.push({temp->right, {x+1, y+1}});
        }

        for(auto it1 : mp){
            vector<int> col;
            for(auto it2 : it1.second){
                col.insert(col.end(), it2.second.begin(), it2.second.end());
            }
            res.push_back(col);
        }

        return res;

    }
};
