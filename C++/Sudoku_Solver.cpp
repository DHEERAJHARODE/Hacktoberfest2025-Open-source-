//
// Author: Ananya Arya
// GitHub: Ananya14-11
// Date: 2025-10-05
// Description: C++ program to solve a Sudoku puzzle using a backtracking algorithm.
//

#include <iostream>
#include <vector>

// Define the size of the Sudoku grid (N x N)
#define N 9

/**
 * @brief Prints the Sudoku grid to the console.
 * @param grid The 9x9 Sudoku grid.
 */
void printGrid(const std::vector<std::vector<int>>& grid) {
    for (int row = 0; row < N; ++row) {
        if (row % 3 == 0 && row != 0) {
            std::cout << "-----------------------" << std::endl;
        }
        for (int col = 0; col < N; ++col) {
            if (col % 3 == 0 && col != 0) {
                std::cout << "| ";
            }
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Checks if it's safe to place a number in a given cell.
 * This function checks the current row, column, and 3x3 sub-grid
 * to ensure there are no duplicates.
 * @param grid The Sudoku grid.
 * @param row The row index of the cell.
 * @param col The column index of the cell.
 * @param num The number to check for placement.
 * @return True if it's safe to place the number, false otherwise.
 */
bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // Check if the number is already present in the current row
    for (int x = 0; x < N; ++x) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check if the number is already present in the current column
    for (int x = 0; x < N; ++x) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

/**
 * @brief Solves the Sudoku puzzle using a recursive backtracking algorithm.
 * It finds an empty cell (represented by 0) and tries to fill it with a valid number.
 * @param grid The Sudoku grid, passed by reference to be modified.
 * @return True if a solution is found, false otherwise.
 */
bool solveSudoku(std::vector<std::vector<int>>& grid) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // Find the first empty cell (value 0)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If there are no empty cells, the puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing numbers 1 through 9 in the empty cell
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            // If it's safe, make the assignment
            grid[row][col] = num;

            // Recur for the rest of the grid
            if (solveSudoku(grid)) {
                return true; // If the recursive call finds a solution
            }

            // If the assignment doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // If no number can be placed in this cell, trigger backtracking
    return false;
}

int main() {
    // Example of an unsolved Sudoku puzzle. 0 represents an empty cell.
    std::vector<std::vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    std::cout << "Unsolved Sudoku Puzzle:" << std::endl;
    printGrid(grid);
    std::cout << "\nSolving...\n" << std::endl;

    if (solveSudoku(grid)) {
        std::cout << "Solved Sudoku Puzzle:" << std::endl;
        printGrid(grid);
    } else {
        std::cout << "No solution exists for the given Sudoku puzzle." << std::endl;
    }

    return 0;
}
