class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int limit = nums.size()/3;
        unordered_map<int,int>count;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        for(auto &pair : count ){
            if(pair.second > limit){
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};
