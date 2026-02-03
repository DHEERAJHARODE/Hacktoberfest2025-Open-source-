#include <bits/stdc++.h>
using namespace std;

bool subSum(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int  i = 0 ; i < sum+1 ; i++) {
        dp[0][i]=false;
    }
    for(int  i = 0 ; i < n+1 ; i++) {
        dp[i][0]=true;
    }

    for(int i = 1 ; i < n+1 ; i++) {
        for(int j = 1 ; j < sum+1 ; j++) {
            if(arr[i-1]<=sum){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];

}

bool equalSum(int arr[], int n){
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum+=arr[i];
    }

    if(sum%2!=0) return false;
    else return subSum(arr, n, sum/2);
}




int main(){
    int arr[] = {1,3,2,5,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    if(equalSum(arr,n)){ cout<<"Yes"<<endl;}
    else cout<<"No"<<endl;
    return 0;
}
