import java.util.*;
class Solution {
    public boolean canPartition(int[] nums) {
        int l=Arrays.stream(nums).sum();
        int N=nums.length;
        if(l%2!=0)
        return false;
        else{
            int sum=l/2;
            boolean[][]dp=new boolean[N+1][sum+1];
            for(int i=0;i<N+1;i++)
            {
                for(int j=0;j<sum+1;j++)
                {
                    if(i==0)
                    dp[i][j]=false;
                    if(j==0)
                    dp[i][j]=true;
                    else if(i!=0 && j!=0)
                    {
                        if(nums[i-1]<=j)
                        {
                            dp[i][j]=(dp[i-1][j-nums[i-1]] || dp[i-1][j]);
                        }
                        else{
                            dp[i][j]=dp[i-1][j];
                        }
                    }
                    
                }
                
            }
            return dp[N][sum];
        }
    }
}