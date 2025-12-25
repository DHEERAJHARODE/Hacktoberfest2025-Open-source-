#include<iostream>
#include<vector>
using namespace std;
//Top down
int mincoin(int target, vector<int>arr,vector<int>dp) {
//basecase
    if(target==0)
        return 0;
    if(target<0)
        return INT_MAX;
    if(dp[target]!=-1)
        return dp[target];
    int mini=INT_MAX;
    for(int i=0; i<arr.size(); i++) {
        int ans = mincoin(target-arr[i],arr,dp);
        if(ans!=INT_MAX)
            mini = min(mini, 1+ans);

    }
    return dp[target] = mini;
}
//Bottom up
int tab(int t,vector<int>arr) {
    vector<int>dp(t+1,INT_MAX);
    dp[0]=0;
    for(int target = 0; target<=t; target++) {
        int mini=INT_MAX;
        for(int i=0; i<arr.size(); i++) {
            if(target-arr[i]>=0) {
                int ans = dp[target-arr[i]];
                if(ans!=INT_MAX)
                    mini = min(mini, 1+ans);
            }
        }
       dp[target]=mini;
    }
    return dp[t];
}   
    int main()
    {
        int n = 7;
        //cout<<"enter the target";
        vector<int>arr;
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);
        vector<int>dp(n+1,-1);
        int ans1 = mincoin(n,arr,dp);
        int ans = tab(n,arr);
        if(ans == INT_MAX)
            ans=-1;
        cout<<"ans is -> "<<ans<<endl;
        return 0;
    }
