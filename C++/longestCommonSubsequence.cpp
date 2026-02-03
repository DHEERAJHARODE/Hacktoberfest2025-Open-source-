#include <bits/stdc++.h>
using namespace std;

int lcs(int ind1, int ind2, string s, string t,vector<vector<int>> &dp) {
    if(ind1 == 0 || ind2 == 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s[ind1-1] == t[ind2-1]) return dp[ind1][ind2] = 1 + lcs(ind1-1, ind2-1, s, t, dp);
    return dp[ind1][ind2] = max(lcs(ind1-1, ind2, s, t, dp), lcs(ind1, ind2-1, s, t, dp));
}

string LCS(string s, string t) {
    int n = s.size();
    int m = t.size();

    int ind1 = n;
    int ind2 = m;
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // Memoisation
    // lcs(ind1, ind2, s, t, dp);

    //Tabulation
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=m; j++) dp[0][j] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[n][m];
    string ans = "";
    for(int i=0; i<len; i++) ans += '&';
    int ind = len-1;

    int i=n, j=m;
    while(i>0 && j>0) {
        if(s[i-1] == t[j-1]) {
            ans[ind--] = s[i-1];
            i--, j--;
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    return ans;
}

int main() {
    string str1 = "abcde";
    string str2 = "bdgef";
    cout<<LCS(str1, str2);   
    return 0;
}