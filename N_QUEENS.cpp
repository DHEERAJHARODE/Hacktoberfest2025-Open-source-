#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int duprow = row; // seeing for the upper diagonal
        int dupcol = col;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = duprow; // seeing for left col.
        col = dupcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = duprow; // seeing for down diagonal
        col = dupcol;
        while (col >= 0 && row < n)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row++;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

int main()
{
    int n = 4;
    Solution s;
    vector<vector<string>> ans;
    ans = s.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            string s = ans[i][j];
            for (int k = 0; k < s.size(); k++)
            {
                cout << s[k];
            }
            cout<<", ";
        }
        cout << endl; // Print a blank line to separate different solutions.
    }

    return 0;
}
