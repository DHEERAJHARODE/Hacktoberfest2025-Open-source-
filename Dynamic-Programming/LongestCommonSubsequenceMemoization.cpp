// Longest Common Subsequence Memoization using DP

#include<iostream>

using namespace std;

int dp[100][100];

int lcs(string s1, string s2, int n, int m)
{
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(s1[m-1]==s2[n-1])
        dp[n][m]= 1+lcs(s1,s2,m-1,n-1);
    else
        dp[n][m]= max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    return dp[n][m];
}

int main(){
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            dp[i][j]=-1;
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    cout<<lcs(s1,s2,n,m);
}
