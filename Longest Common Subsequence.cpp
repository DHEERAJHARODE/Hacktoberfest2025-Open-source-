#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
       int fun(string text1, string text2,int n,int m, vector<vector<int>> &dp)
    {
        if(dp[n][m]!=-1)return dp[n][m];
        if(n==0 || m==0)return 0;
        
        
        if(text1[n-1] == text2[m-1])
            return dp[n][m] = 1+fun(text1, text2, n-1, m-1,dp);
        else
            return dp[n][m] = max(fun(text1, text2, n, m-1,dp),fun(text1, text2, n-1, m,dp));
    }
    
    int lcs(int n, int m, string text1, string text2)
    {
        
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(text1,text2,n,m,dp);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends