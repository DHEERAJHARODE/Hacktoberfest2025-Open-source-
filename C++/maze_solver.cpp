#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Cell {
    bool visited;
    bool top, bottom, left, right;
    Cell() : visited(false), top(true), bottom(true), left(true), right(true) {}
};

class Maze {
    int rows, cols;
    vector<vector<Cell>> grid;
    vector<pair<int, int>> solutionPath;

public:
    Maze(int r, int c) : rows(r), cols(c), grid(r, vector<Cell>(c)) {
        srand(time(0));
        generateMaze(0, 0);
    }

    void generateMaze(int x, int y) {
        grid[x][y].visited = true;
        vector<pair<int, int>> neighbors = {
            {x-1, y}, {x, y+1}, {x+1, y}, {x, y-1}
        };
        random_shuffle(neighbors.begin(), neighbors.end());

        for (auto [nx, ny] : neighbors) {
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !grid[nx][ny].visited) {
                if (nx == x-1) { grid[x][y].top = false; grid[nx][ny].bottom = false; }
                if (nx == x+1) { grid[x][y].bottom = false; grid[nx][ny].top = false; }
                if (ny == y-1) { grid[x][y].left = false; grid[nx][ny].right = false; }
                if (ny == y+1) { grid[x][y].right = false; grid[nx][ny].left = false; }
                generateMaze(nx, ny);
            }
        }
    }

    bool solveMaze(int x, int y, int endX, int endY) {
        grid[x][y].visited = true;
        solutionPath.push_back({x, y});
        if (x == endX && y == endY) return true;

        vector<pair<int, int>> moves = {
            {x-1, y}, {x, y+1}, {x+1, y}, {x, y-1}
        };
        for (auto [nx, ny] : moves) {
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !grid[nx][ny].visited) {
                if ((nx == x-1 && !grid[x][y].top) ||
                    (nx == x+1 && !grid[x][y].bottom) ||
                    (ny == y-1 && !grid[x][y].left) ||
                    (ny == y+1 && !grid[x][y].right)) {
                    if (solveMaze(nx, ny, endX, endY)) return true;
                }
            }
        }
        solutionPath.pop_back();
        return false;
    }

    void printMaze(bool showSolution = false) {
        for (int i = 0; i < rows; ++i) {
            // Print top walls
            for (int j = 0; j < cols; ++j)
                cout << (grid[i][j].top ? "+---" : "+   ");
            cout << "+\n";
            // Print left walls and solution path
            for (int j = 0; j < cols; ++j) {
                cout << (grid[i][j].left ? "|" : " ");
                bool isSolution = false;
                if (showSolution) {
                    for (auto [sx, sy] : solutionPath)
                        if (sx == i && sy == j) isSolution = true;
                }
                cout << (isSolution ? " * " : "   ");
            }
            cout << (grid[i][cols-1].right ? "|\n" : "\n");
        }
        // Print bottom walls
        for (int j = 0; j < cols; ++j)
            cout << "+---";
        cout << "+\n";
    }

    void resetVisited() {
        for (auto& row : grid)
            for (auto& cell : row)
                cell.visited = false;
    }

    void run() {
        printMaze();
        resetVisited();
        cout << "Solving maze...\n";
        if (solveMaze(0, 0, rows-1, cols-1)) {
            printMaze(true);
        } else {
            cout << "No solution found!\n";
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter maze size (rows cols): ";
    cin >> rows >> cols;
    Maze maze(rows, cols);
    maze.run();
    return 0;
}
