/* we have given two strings s and t, and we have to return the length of their longest common subsequence.
if there is no common subsequence then answer will be zero*/

#include<bits/stdc++.h>
using namespace std

int findLongestCommonSub(int i, int j, string &s, string &t, vector<vector<int>>&dp){//i and j are the current index of string s and t respectively
    if(i<0 || j<0)return 0;  // Base Condition: if we got  out of the range of strings

    if(dp[i][j] != -1)return dp[i][j];

    if(s[i] == t[j])return dp[i][j] = 1 + findLongestCommonSub(i-1, j-1, s, t, dp); // if we get char of both strings equal 

    return dp[i][j] = max(findLongestCommonSub(i-1,j,s,t,dp), findLongestCommonSub(i,j-1,s,t,dp)); // if we don't get, then decrease either of index and take max of both
  
}
int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));  // initializing dp for storing values calculated previously

        return findLongestCommonSub(m-1, n-1, s, t, dp);
}

/* 
Time complexity : O(m*n)
Space complexity : O(m*n) + O(m)(stack space)
  */

int main(){
  string s = "abcde";
  string t = "ace";
  cout<<longestCommonSubsequence(s,t)<<endl;

  return 0;
}
