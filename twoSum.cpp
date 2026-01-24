// here is an optimal solution to problem - two sum present on leetcode 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];

            if(mpp.find(x)!=mpp.end() && mpp[x]!=i){
                ans.push_back(i);
                ans.push_back(mpp[x]);
                break;
            }
        }
        return ans;
    }
};
