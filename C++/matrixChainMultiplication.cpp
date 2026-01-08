#include <bits/stdc++.h>
using namespace std;

int solveMCMRecursive(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_ans = solveMCMRecursive(arr, i, k) + solveMCMRecursive(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, temp_ans);
    }
    return ans;
}
int static dp[1001][1001]; // based on contraints
int solveMCMMemo(int arr[], int i, int j)
{
    // top down approach
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp_ans = solveMCMMemo(arr, i, k) + solveMCMMemo(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, temp_ans);
    }

    return dp[i][j] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solveMCMRecursive(arr, 1, n - 1) << endl;
    cout << solveMCMMemo(arr, 1, n - 1);

    return 0;
}
