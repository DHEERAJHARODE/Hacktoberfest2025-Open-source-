#include <bits/stdc++.h>
using namespace std;
#define N 50

//Frog jump using dp
int h[N];
int dp[N];


int fun(int n)
{
    int cost=INT_MAX;
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    
    cost=min(cost,fun(n-1)+abs(h[n]-h[n-1]));
    if(n>1)
    cost=min(cost,fun(n-2)+abs(h[n]-h[n-2]));
    return dp[n]=cost;
}
int main()
{
   memset(dp,-1,sizeof(dp));
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>h[i];
   }
    cout<<fun(n-1);
    return 0;
};