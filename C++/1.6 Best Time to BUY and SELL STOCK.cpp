class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit=0;
      int buy=prices[0];
      for(int i=1;i<prices.size();i++){
          if(buy>prices[i])
              buy=prices[i];
          if(profit<prices[i]-buy)
              profit=prices[i]-buy;
      }
       return profit; 
    }
};
