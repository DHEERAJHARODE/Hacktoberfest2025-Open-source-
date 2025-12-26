#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int dp[1005];
  int func(int len,vector<int> &prices)
  {
      if(len==0) return 0;
      int ans=0;
      if(dp[len]!=-1) return dp[len];
      for(int len_to_cut=1;len_to_cut<=len;len_to_cut++)
      {
          if(len>=len_to_cut)
          {
              ans=max(ans,func(len-len_to_cut,prices)+prices[len_to_cut-1]);
          }
      }
      return dp[len]=ans;
      
  }
    int cutRod(int price[], int n) 
    {
        memset(dp,-1,sizeof(dp));
        vector <int>prices(price,price+n);
        return func(n,prices);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
} 