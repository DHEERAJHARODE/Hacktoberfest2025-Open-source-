#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10010];
    int func(vector<int>& coins, int amount)
    {
        if(dp[amount]!=-1) return dp[amount];
        if(amount==0) return 0;
        int ans=INT_MAX;
        for(auto coin:coins)
        {
            if(amount-coin>=0)
            {
                ans=min(ans +0LL,func(coins,amount-coin)+1LL);
            }
        }
        return dp[amount]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
       memset(dp,-1,sizeof(dp));
        int ans=func(coins,amount);
        if(ans==INT_MAX) 
        {
            return -1;
        }
        else
        {
            return ans;
        }
        
    }
};
int main()
{
    vector<int> v={1,2,3,4};
    int amount=24;
    Solution sol;
    int ans=sol.coinChange(v,amount);
    cout<<ans;
    

    return 0;
}
