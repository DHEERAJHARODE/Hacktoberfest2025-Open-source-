#include <iostream>
#include <math.h>
using namespace std;
bool isSafe(int board[][9], int i, int j, int no, int n)
{
    // row and col mai nhi hona chahiye
    for (int k = 0; k < n; k++)
    {
        if (board[i][k] == no || board[k][j] == no)
        {
            return false;
        }
    }

    // daba checking idhar hogi
    n = sqrt(n);
    int si = (i / n) * n;
    int sj = (j / n) * n;
    for (int k = si; k < si + n; k++)
    {
        for (int l = sj; l < sj + n; l++)
        {
            if (board[k][l] == no)
            {
                return false;
            }
        }
    }
    return true;
}
bool SudokuSolver(int board[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        for (int l = 0; l < 9; l++)
        {
            for (int m = 0; m < 9; m++)
            {
                cout << board[l][m] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // recursive case
    if (j == n)
    {
        return SudokuSolver(board, i + 1, 0, n); // agar column n pee pohoch jaye toh niche kaar doo
    }
    if (board[i][j] != 0)
    {
        return SudokuSolver(board, i, j + 1, n);
    }
    for (int no = 1; no < 10; no++)
    {
        if (isSafe(board, i, j, no, n))
        {
            board[i][j] = no;
            bool baakisolve = SudokuSolver(board, i, j + 1, n);
            if (baakisolve)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int sudoku[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    SudokuSolver(sudoku, 0, 0, 9);
    return 0;
}
