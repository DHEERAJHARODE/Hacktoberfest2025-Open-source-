#include <bits/stdc++.h>
using namespace std;

/*
// Recursive + Memoization Code [Top Down Approach]
// T.C. -> ( O(N) * k )
// S.C. -> O(N) [Recursion Auxillary Stack Space] + O(N) [1D dp array]

class Solution
{
public:
    int solve(vector<int> &heights, int ind, vector<int> &dp, int k)
    {

        // Base Case
        if (ind == 0)
            return 0;

        // Step 3 : If value of recursion call is already computed , then simply return it
        if (dp[ind] != -1)
            return dp[ind];

        int min_Steps = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (ind - i >= 0)
            {
                int jump_Energy_Required = solve(heights, ind - i, dp, k) + abs(heights[ind] - heights[ind - i]);
                min_Steps = min(min_Steps, jump_Energy_Required);
            }
        }

        // Step 2 : Store the Returning value of recursion call in dp array
        return dp[ind] = min_Steps;
    }

    int KfrogJump(vector<int> heights, int n, int k)
    {

        // Step 1 : Declare a 1D DP array
        vector<int> dp(n + 1, -1);
        return solve(heights, n - 1, dp, k);
    }
};
*/

// Tabulation Code [Bottom Up Approach]
// T.C. -> o(N * k)
// S.C. -> O(N) [1D dp array]

class Solution
{
public:
    int KfrogJump(vector<int> heights, int n, int k)
    {
        vector<int> dp(n, 0);
        dp[0] = 0;
        int minSteps = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump_Energy_Required = dp[i - j] + abs(heights[i] - heights[i - j]);
                    minSteps = min(minSteps, jump_Energy_Required);
                    dp[i] = minSteps;
                }
            }
        }
        return dp[n - 1];
    }
};

int main()
{

    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    int k = 3;

    Solution obj;
    int ans = obj.KfrogJump(heights, n, k);

    cout << "\nHeights array is: " << endl;
    for (auto it : heights)
        cout << " " << it << " ";
    cout << "\n\nMinimum Energy used by the frog to reach from 1st to Nth stair Using " << k << " Jumps is: " << ans << endl;

    return 0;
}