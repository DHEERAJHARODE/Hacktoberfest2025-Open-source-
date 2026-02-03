#include <iostream>
#include <vector>
using namespace std;

// The solve function checks if the word can be formed starting from position (i, j) on the board
bool solve(vector<vector<char>>& b, string & w, int index, int i, int j, int n, int m) {
    if (index == w.size()) {
        return true; // If the entire word has been found, return true
    }
    if (i < 0 || i >= n || j < 0 || j >= m || b[i][j] != w[index]) {
        return false; // If the current position is out of bounds or doesn't match the word, return false
    }
    char original = b[i][j];
    b[i][j] = '*'; // Mark the cell as visited to avoid revisiting it
    
    bool nextWord = solve(b, w, index + 1, i + 1, j, n, m) || 
                    solve(b, w, index + 1, i - 1, j, n, m) || 
                    solve(b, w, index + 1, i, j + 1, n, m) || 
                    solve(b, w, index + 1, i, j - 1, n, m) ;
    
    b[i][j] = original; // Restore the original character at this cell
    return nextWord;
}

// The present function checks if the word can be found on the board
bool present(vector<vector<char>> & board, string & word, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (solve(board, word, 0, i, j, n, m)) {
                return true; // If the word can be formed starting from (i, j), return true
            }
        }
    }
    return false; // If the word cannot be found anywhere on the board, return false
}

int main() {
    // Define the board as a 2D vector of characters
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    string word = "ABCCED"; // Word to search for in the board

    int n = board.size(); // Number of rows in the board
    int m = board[0].size(); // Number of columns in the board

    // Check if the word can be found on the board
    if (present(board, word, n, m)) {
        cout << "Word '" << word << "' is present on the board." << endl;
    } else {
        cout << "Word '" << word << "' is not present on the board." << endl;
    }

    return 0;
}
