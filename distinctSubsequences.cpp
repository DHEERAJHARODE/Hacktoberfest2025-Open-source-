class Solution {
public:
    int mod = 1e9 + 7;
    
    int distinctSubsequences(string s) {
        int n = s.size();
        
        vector<int> last(26, -1);
        long long dp[n + 1];
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] * 2;
            int lastOccur = last[s[i - 1] - 'a'];
            
            if (lastOccur != -1) {
                dp[i] -= dp[lastOccur];
                if (dp[i] < 0)
                    dp[i] += mod;
            }
            dp[i] %= mod;
            last[s[i - 1] - 'a'] = i - 1;
        }
        return dp[n];
    }
};
