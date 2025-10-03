class Solution {
public:
    int search(int x, vector<int>& ans) {
        int sum=0; int t=1;
        for(int j=0; j<ans.size(); j++) {
            if(sum + ans[j] <= x) sum += ans[j];
            else {
                t++;
                sum=ans[j];
            }
        }
        return t;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;

        int s=0; int e=0;
        for(int i=0; i<nums.size(); i++) {
            if(s < nums[i]) s = nums[i];
            e += nums[i];
        }

        while(s <= e) {
            int mid = s+(e-s)/2;
            if(search(mid,nums) <= k) e = mid-1;
            else s = mid+1;
        }
        return s;
    }
};
