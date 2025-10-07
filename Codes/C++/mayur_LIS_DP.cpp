#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Increasing Subsequence
int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = length of LIS ending at index i
    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Length of Longest Increasing Subsequence: "
         << longestIncreasingSubsequence(nums) << endl;
    return 0;
}
