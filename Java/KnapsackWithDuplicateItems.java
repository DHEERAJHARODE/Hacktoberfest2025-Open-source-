/*
Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

*/
class KnapsackWithDuplicateItems{
    static int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
         int[] dp = new int[W + 1];
        
        for (int i = 0; i <= W; i++) {
            for (int j = 0; j < N; j++) {
                if (wt[j] <= i) {
                    dp[i] = Math.max(dp[i], dp[i - wt[j]] + val[j]);
                }
            }
        }
        
        return dp[W];
    }
}
