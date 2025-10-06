// Problem: N-Queens Problem
// Description: Place N queens on an N×N chessboard so that no two queens attack each other.
// This solution prints all possible solutions using backtracking.

class NQueens {
    static int N = 4; // Board size (can change)

    // Function to print the chessboard
    static void printSolution(int board[][]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(board[i][j] + " ");
            System.out.println();
        }
        System.out.println();
    }

    // Check if placing a queen at board[row][col] is safe
    static boolean isSafe(int board[][], int row, int col) {
        // Check row on left
        for (int i = 0; i < col; i++)
            if (board[row][i] == 1) return false;

        // Check upper diagonal on left
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1) return false;

        // Check lower diagonal on left
        for (int i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j] == 1) return false;

        return true;
    }

    // Recursive utility to solve the problem
    static boolean solveNQUtil(int board[][], int col) {
        if (col >= N) {
            printSolution(board); // Found one solution
            return true; // Continue searching for all solutions
        }

        boolean res = false;
        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;
                res = solveNQUtil(board, col + 1) || res;
                board[i][col] = 0; // BACKTRACK
            }
        }
        return res;
    }

    // Main function
    public static void main(String args[]) {
        int board[][] = new int[N][N];

        if (!solveNQUtil(board, 0))
            System.out.println("No solution exists");
    }
}
