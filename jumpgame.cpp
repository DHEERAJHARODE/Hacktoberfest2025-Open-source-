class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),max_idx=nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i]>=max_idx){max_idx=nums[i];}
            else{max_idx--;}
            if(max_idx<=0){return false;}
        }
        return true;
    }
};
