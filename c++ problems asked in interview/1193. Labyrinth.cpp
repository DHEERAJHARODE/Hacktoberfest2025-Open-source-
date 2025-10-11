/*
 * Author: Kaylin Yang
 * Date: Oct 11, 2025
 * Description:
 * You have a grid (maze) with n rows and m columns. Each cell is one of:
 * . = empty floor (you can walk here)
 * # = wall (you cannot go there)
 * A = your starting point
 * B = your target / end point
 * You want to find a path from A to B moving only in the four cardinal directions (up, down, left, right).
 * You must answer:
 * Whether such a path exists (print “YES” or “NO”).
 * If yes, also print:
 * The length (number of moves) of the shortest path.
 * One valid sequence of moves (L = left, R = right, U = up, D = down) that takes you from A to B in that many steps.
 * If there is no way to reach B from A, just print “NO”.
 * Test Cases:
 * Input: 
 * 5 8
    ########
    #.A#...#
    #.##.#B#
    #......#
    ########
 * Output: 
    YES
    9
    LDDRRRRRU
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
        int n, m;
        cin >> n >> m;
        vector<string> labyrinth(n);
        queue<pair<int, int>> q;
        int a_row, a_col, b_row, b_col;
        for (int i = 0; i < n; i++) {
                cin >> labyrinth[i];
                for (int j = 0; j < m; j++) {
                        if (labyrinth[i][j] == 'A') {
                                a_row = i;
                                a_col = j;
                                q.push({i, j});
                        } else if (labyrinth[i][j] == 'B') {
                                b_row = i;
                                b_col = j;
                        }
                }
        }

        // Directions: Up, Right, Down, Left
        vector<int> dirR{-1, 0, 1, 0};
        vector<int> dirC{0, 1, 0, -1};
        vector<vector<int>> arrive(n, vector<int>(m, -1));

        while (!q.empty()) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                        int nextR = row + dirR[i], nextC = col + dirC[i];
                        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m &&
                            labyrinth[nextR][nextC] != '#' && arrive[nextR][nextC] == -1) {
                                arrive[nextR][nextC] = i;
                                q.push({nextR, nextC});
                        }
                }
        }

        if (arrive[b_row][b_col] == -1) {
                cout << "NO" << endl;
        } else {
                string res = "", dir = "URDL";
                int row = b_row, col = b_col;
                while (row != a_row || col != a_col) {
                        int ind = arrive[row][col];
                        res += dir[ind];
                        row -= dirR[ind];
                        col -= dirC[ind];
                }
                reverse(res.begin(), res.end());
                cout << "YES\n" << res.length() << "\n" << res << endl;
        }
}