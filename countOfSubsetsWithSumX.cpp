#include <bits/stdc++.h>
using namespace std;

void countSubSum(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i = 0 ; i < sum+1 ; i++) {
        dp[0][i]=0;
    }

    for(int j = 0 ; j < n+1 ; j++) {
        dp[j][0]=1;
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= sum ; j++) {
            if(arr[n-1]<=sum){
                dp[i][j] = dp[i ][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
    return;
}


int main(){
    int arr[] = {3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    countSubSum(arr,n,x);
    return 0;
}
