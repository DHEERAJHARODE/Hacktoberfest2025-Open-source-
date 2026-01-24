#include <bits/stdc++.h>
using namespace std;

// Multiplies two matrices mat1[][]
// and mat2[][] and prints result.
// (m1) x (m2) and (n1) x (n2) are
// dimensions of given matrices.
void multiply(int m1, int m2, int mat1[][2], int n1, int n2,
              int mat2[][2])
{
    int x, i, j;
    int res[m1][n2];
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            res[i][j] = 0;
            for (x = 0; x < m2; x++) {
                *(*(res + i) + j) += *(*(mat1 + i) + x)
                                     * *(*(mat2 + x) + j);
            }
        }
    }
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            cout << *(*(res + i) + j) << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int mat1[][2] = { { 1, 1 }, { 2, 2 } };
    int mat2[][2] = { { 1, 1 }, { 2, 2 } };
    int m1 = 2, m2 = 2, n1 = 2, n2 = 2;
    multiply(m1, m2, mat1, n1, n2, mat2);
    return 0;
}
