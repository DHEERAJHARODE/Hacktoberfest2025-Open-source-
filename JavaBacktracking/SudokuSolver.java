// Problem: Sudoku Solver
// Description: Solve a 9x9 Sudoku puzzle using backtracking.
// '0' represents empty cells that need to be filled.

class SudokuSolver {
    static int N = 9; // Sudoku size

    // Utility function to print the board
    static void printBoard(int board[][]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(board[i][j] + " ");
            System.out.println();
        }
        System.out.println();
    }

    // Check if placing num at board[row][col] is valid
    static boolean isSafe(int board[][], int row, int col, int num) {
        // Check row and column
        for (int x = 0; x < N; x++) {
            if (board[row][x] == num || board[x][col] == num)
                return false;
        }

        // Check 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[startRow + i][startCol + j] == num)
                    return false;

        return true;
    }

    // Recursive function to solve Sudoku
    static boolean solveSudoku(int board[][], int row, int col) {
        if (row == N - 1 && col == N) // reached end
            return true;

        if (col == N) { // move to next row
            row++;
            col = 0;
        }

        if (board[row][col] != 0) // skip filled cells
            return solveSudoku(board, row, col + 1);

        for (int num = 1; num <= 9; num++) {
            if (isSafe(board, row, col, num)) {
                board[row][col] = num;
                if (solveSudoku(board, row, col + 1))
                    return true;
                board[row][col] = 0; // BACKTRACK
            }
        }
        return false;
    }

    // Main function
    public static void main(String args[]) {
        int board[][] = {
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

        if (solveSudoku(board, 0, 0))
            printBoard(board);
        else
            System.out.println("No solution exists");
    }
}
