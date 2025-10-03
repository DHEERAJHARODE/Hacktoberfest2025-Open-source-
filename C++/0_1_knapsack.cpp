#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &A, vector<int> &B, int w, int n, vector<vector<int>> &dp) {
    if (n == 0 || w == 0) return 0;

    if (dp[n][w] != -1) return dp[n][w];

    if (B[n - 1] <= w) {
        dp[n][w] = max(
            A[n - 1] + knapsack(A, B, w - B[n - 1], n - 1, dp),
            knapsack(A, B, w, n - 1, dp)
        );
    } else {
        dp[n][w] = knapsack(A, B, w, n - 1, dp);
    }

    return dp[n][w];
}

int solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, -1));
    return knapsack(A, B, C, n, dp);
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    cout << "Max value in Knapsack = " << solve(values, weights, capacity) << endl;
    return 0;
}
