// 0/1 knapsack problem using dynamic programming

#include<iostream>

using namespace std;

int val[100];
int wt[100];
int dp[100][100];

int knapsack(int n, int w){
    if(n == 0 || w == 0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(wt[n-1] > w){
        dp[n][w] = knapsack(n-1, w);
    }
    else{
        dp[n][w] = max(knapsack(n-1, w), val[n-1] + knapsack(n-1, w-wt[n-1]));
    }
    return dp[n][w];
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> wt[i] >>  val[i];
    }
    int w;
    cin >> w;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, w) << endl;
    return 0;
}
