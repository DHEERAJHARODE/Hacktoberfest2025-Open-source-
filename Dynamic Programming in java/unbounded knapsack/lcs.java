//      Recursive Approach


class Solution
{
    //Function to find the length of longest common subsequence in two strings.
    static int lcs(int x, int y, String s1, String s2)
    {
        // your code here
        if(x==0 || y==0)
        return 0;
        if(s1.charAt(x-1)==s2.charAt(y-1))
        return 1+lcs(x-1,y-1,s1,s2);
        else{
            return Math.max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
        }
    }
    
}



// Recursive+storage = Memoization
 


class Solution
{
    static int solve(int x,int y,String s1,String s2,int[][] dp)
    {
        if(x==0 || y==0)
        return 0;
        if(dp[x][y]!=-1)
        return dp[x][y];
        if(s1.charAt(x-1)==s2.charAt(y-1))
        {
            dp[x][y]=1+lcs(x-1,y-1,s1,s2);
            return dp[x][y];
        }
        else{
            dp[x][y]=Math.max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
            return dp[x][y];
        }
    }
    //Function to find the length of longest common subsequence in two strings.
    static int lcs(int x, int y, String s1, String s2)
    {
        // your code here
        int[][] dp=new int[x+1][y+1];
    for (int[] row: dp)
    Arrays.fill(row, -1);
        return solve(x,y,s1,s2,dp);
        
    }
    
}



// Tabulization


class Solution
{
    static int solve(int x,int y,String s1,String s2)
    {
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
        return dp[x][y];
    }
    //Function to find the length of longest common subsequence in two strings.
    static int lcs(int x, int y, String s1, String s2)
    {
        return solve(x,y,s1,s2);
    }
    
}