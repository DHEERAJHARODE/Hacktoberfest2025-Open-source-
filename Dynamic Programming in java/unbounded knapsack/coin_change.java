
class Solution {
    public long count(int coins[], int N, int sum) {
        // code here.
        int n=coins.length;
        long[][] dp=new long[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0 && j==0)
                dp[i][j]=1;
                else if(i==0)
                dp[i][j]=0;
                else{
                    if(j-coins[i-1]>=0)
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                    else
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
}
