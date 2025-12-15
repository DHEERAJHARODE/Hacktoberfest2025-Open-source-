public class printing_lcs {
    static int[][] solve(int x,int y,String s1,String s2)
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
        return dp;
    }
    static String solve2(String s1, String s2){
        int[][] dp=solve(s1.length(),s2.length(), s1, s2);
        int i=s1.length();
        int j=s2.length();
        String ans="";
        while(i==0 && j==0)
        {
            if(s1.charAt(i-1)==s2.charAt(j-1))
            {
                ans+=s1.charAt(i);
                i--;
                j--;
             }
            else{
                if(dp[i][j-1]>=dp[i-1][j])
                j--;
                else
                i--;
            }

        }
        return ans;
    }
}
