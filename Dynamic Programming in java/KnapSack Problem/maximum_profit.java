
import java.util.*;
public class maximum_profit{
    static int maxProfit(int[] wt,int[] val,int tw,int n){
        if(n==0|| tw==0)
        return 0;
        if(wt[n-1]<=tw)
        return Math.max(val[n-1]+maxProfit(wt, val, tw-wt[n-1], n-1),maxProfit(wt, val, tw, n-1));
        return maxProfit(wt, val, tw, n-1);
    }
    static int maxProfit_iterative(int[] wt, int[] val,int tw,int n){
        int[][] dp=new int[n+1][tw+1];
        int j=0,i=0;
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<tw+1;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
                else if(wt[i-1]<=j)
                {
                    dp[i][j]=Math.max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][tw];
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] wt=new int[n];
        int[] val=new int[n];
        int tw=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            wt[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            val[i]=sc.nextInt();
        }
        System.out.println("iterative");
        System.out.println(maxProfit_iterative(wt, val,tw, n));
        System.out.println("recursive");
        System.out.println(maxProfit(wt, val, tw, n));
        

    }
}
