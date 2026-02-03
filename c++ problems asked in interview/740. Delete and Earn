class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 200001;
        vector<int> sum(n,0);
        
        for(int num : nums)
            sum[num] += num;
        
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = sum[1];
        
        for(int i=2;i<n;i++)
            dp[i] = max(dp[i-1], sum[i] + dp[i-2]);
        
        return dp[n-1];
    }
};
