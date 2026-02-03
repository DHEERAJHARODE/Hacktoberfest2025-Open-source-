//leetcode - Best Time to Buy and Sell Stock.

public class Best_Time_to_Buy_and_Sell_Stock {
    public static void main(String[] args) {
        int[]prices = {7,1,5,3,6,4};
        System.out.println(maxProfit(prices));
    }
    public static int maxProfit(int[] prices) {
        int n = prices.length;
        if(n<=1){
            return 0;
        }
        int min = prices[0];
        int profit = 0;
        for(int i = 0;i<n;i++){
            int current = prices[i];
            if(min>prices[i]){
                min = prices[i];
            }
            else{
                int max = current - min;
                if(max > profit){
                    profit = max;
                }
            }

        
    }
    return profit;
}
}
