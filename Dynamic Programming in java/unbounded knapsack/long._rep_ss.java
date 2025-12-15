class Solution
{
    public int LongestRepeatingSubsequence(String S)
    {
        // code here
        
        
        //code here
        int n=S.length();
        int[][] dp=new int[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if((i==0 || j==0 ))
                dp[i][j]=0;
                else{
                    if(S.charAt(i-1)==S.charAt(j-1) && i!=j)
                    dp[i][j]=1+dp[i-1][j-1];
                    else
                    dp[i][j]=Math.max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
}