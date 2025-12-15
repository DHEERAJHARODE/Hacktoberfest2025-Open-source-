class Solution
{
	public int minOperations(String s1, String s2) 
	{ 
	    // Your code goes here
	    int x=s1.length();
	    int y=s2.length();
	    int[][] dp=new int[x+1][y+1];
        for(int i=0;i<x+1;i++)
        {
            for(int j=0;j<y+1;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
                else{
                    if(s1.charAt(i-1)==s2.charAt(j-1))
                    dp[i][j]=1+dp[i-1][j-1];
                    else{
                        dp[i][j]=Math.max(dp[i][j-1],dp[i-1][j]);
                    }
                }
            }
        }
        return s1.length()-2*dp[x][y]+s2.length();
	} 
}