/** Minimum Falling Path Sum **/
/** Question Link : https://leetcode.com/problems/minimum-falling-path-sum/ **/

/**Code **/

class Solution
{
public:
    // Recursive Approach: 
    /*
    int dp[105][105];
    int f(int i,int j,vector<vector<int>>& matrix)
    {
        if(j<0 || j >matrix.size()-1) return 1e9;
        if(i==0)return matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int u =  f(i-1,j,matrix);
        int ur = f(i-1,j+1,matrix);
        int ul = f(i-1,j-1,matrix);
        return dp[i][j] = min({u,ur,ul}) + matrix[i][j];
    }
    */
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        /** Iterative Approach **/
        int mini = 1e8;
        int n = matrix.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int u = matrix[i][j] + dp[i - 1][j];

                int ul = matrix[i][j];
                if (j - 1 >= 0)
                    ul += dp[i - 1][j - 1];
                else
                    ul += 1e8;

                int ur = matrix[i][j];
                if (j + 1 < n)
                    ur += dp[i - 1][j + 1];
                else
                    ur += 1e8;

                dp[i][j] = min({ul, ur, u});
            }
        }
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, dp[n - 1][i]);
        }
        return mini;
    }
};