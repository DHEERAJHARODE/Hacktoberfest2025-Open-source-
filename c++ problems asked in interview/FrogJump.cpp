int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,0);
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        int f=dp[i-1]+abs(heights[i]-heights[i-1]);
        int s=INT_MAX;
        if(i>1)
         s=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(f,s);
    }
    return dp[n-1];
 
}
