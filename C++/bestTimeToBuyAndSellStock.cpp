class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, maxi = 0, n = prices.size();
        int left = 0, right = 1;

        while (right < n ) {
            if (prices[left] > prices[right]) {
                left = right;
            } else {
                profit = prices[right] - prices[left];
                maxi = max(profit, maxi);
            }

            right++;
        }
        return maxi;
    }
};
