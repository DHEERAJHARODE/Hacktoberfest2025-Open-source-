#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canWeGo(int a, int b, vector<vector<int>> &grid)
{
    return (a < grid.size() and b < grid.size() and a >= 0 and b >= 0) and grid[a][b] == 1;
}

int f(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();
    int ans = 0;
    if (i == n - 1 and j == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "*****\n";

        return 1;
    }

    grid[i][j] = 2;
    if (canWeGo(i, j + 1, grid))
        ans += f(i, j + 1, grid);

    if (canWeGo(i + 1, j, grid))
        ans += f(i + 1, j, grid);

    if (canWeGo(i, j - 1, grid))
        ans += f(i, j - 1, grid);

    if (canWeGo(i - 1, j, grid))
        ans += f(i - 1, j, grid);

    grid[i][j] = 1;
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 1},
        {0, 1, 1, 1}

    };
    int res = f(0, 0, grid);
    cout << res << "\n";
    return 0;
}