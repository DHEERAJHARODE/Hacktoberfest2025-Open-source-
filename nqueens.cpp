#include <iostream>
#include <vector>

using namespace std;

void solveNQueens(int n, vector<int>& col, vector<int>& diag1, vector<int>& diag2, vector<vector<string>>& result, vector<string>& board, int row) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (col[i] || diag1[row+i] || diag2[row-i+n-1]) {
            continue;
        }
        board[row][i] = 'Q';
        col[i] = 1;
        diag1[row+i] = 1;
        diag2[row-i+n-1] = 1;
        solveNQueens(n, col, diag1, diag2, result, board, row+1);
        board[row][i] = '.';
        col[i] = 0;
        diag1[row+i] = 0;
        diag2[row-i+n-1] = 0;
    }
}

vector<vector<string>> nQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    vector<int> col(n, 0), diag1(2*n-1, 0), diag2(2*n-1, 0);
    solveNQueens(n, col, diag1, diag2, result, board, 0);
    return result;
}

int main() {
	int n;
    cin>>n;
    vector<vector<string>> result = nQueens(n);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}

