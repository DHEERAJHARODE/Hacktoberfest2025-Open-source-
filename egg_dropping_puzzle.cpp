#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // n eggs and k floors.
        // your code here
        
        int dp[k+1][n+1];
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
            dp[1][i] =1;
            
        }
        for(int i=2;i<=k;i++)
        {
            dp[i][1] = i;
        }
        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                dp[i][j] = INT_MAX;
                for(int x=1;x<=i;x++){
                    dp[i][j] = min(dp[i][j] , 1 + max(dp[x-1][j-1] , dp[i-x][j]));
                }
            }
        }
        return dp[k][n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
