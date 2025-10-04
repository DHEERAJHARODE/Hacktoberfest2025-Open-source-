import java.util.*;
public class Sudoku {
    static final int N = 9; // Size of Sudoku grid
    // Function to check if placing num at (row, col) is valid
    public static boolean isSafe(int[][] board, int row, int col, int num) {
        // Row check
        for (int x=0;x<N;x++){
            if (board[row][x]==num) return false;
        }
        // Column check
        for (int x=0;x<N;x++){
            if(board[x][col]==num) return false;
        }
        // Subgrid check
        int startRow=row-row%3;
        int startCol=col-col%3;
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if(board[i+startRow][j+startCol]==num) return false;
            }
        }
        return true;
    }
    // Solve Sudoku using Backtracking
    public static boolean solveSudoku(int[][] board, int row, int col) {
        if (row == N - 1 && col == N) return true;
        if (col == N) {
            row++;
            col = 0;
        }
        if (board[row][col] != 0) return solveSudoku(board, row, col + 1);

        for (int num = 1; num <= 9; num++) {
            if (isSafe(board, row, col, num)) {
                board[row][col] = num;
                if (solveSudoku(board, row, col + 1)) return true;
                board[row][col] = 0; // backtrack
            }
        }
        return false;
    }

    // Function to fill diagonal 3x3 boxes (helps in generator)
    public static void fillDiagonal(int[][] board) {
        Random rand = new Random();
        for (int k = 0; k < N; k += 3) {
            boolean[] used = new boolean[10];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num;
                    do {
                        num = rand.nextInt(9) + 1;
                    } while (used[num]);
                    used[num] = true;
                    board[i + k][j + k] = num;
                }
            }
        }
    }
    // Fill remaining Sudoku using solver
    public static void fillRemaining(int[][] board) {
        solveSudoku(board, 0, 0);
    }
    // Remove numbers to create puzzle
    public static void removeDigits(int[][] board, int count) {
        Random rand = new Random();
        while (count > 0) {
            int i = rand.nextInt(N);
            int j = rand.nextInt(N);
            if (board[i][j] != 0) {
                board[i][j] = 0;
                count--;
            }
        }
    }

    // Print Sudoku board
    public static void printBoard(int[][] board) {
        for (int r = 0; r < N; r++) {
            if (r % 3 == 0 && r != 0) System.out.println("------+-------+------");
            for (int d = 0; d < N; d++) {
                if (d % 3 == 0 && d != 0) System.out.print("| ");
                System.out.print(board[r][d] == 0 ? ". " : board[r][d] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[][] board = new int[N][N];

        // Step 1: Generate Sudoku
        fillDiagonal(board);
        fillRemaining(board);

        System.out.println("Generated Sudoku Puzzle:");
        int[][] puzzle = new int[N][N];
        for (int i = 0; i < N; i++) puzzle[i] = board[i].clone();

        removeDigits(puzzle, 40); // Remove 40 cells for medium difficulty
        printBoard(puzzle);

        // Step 2: Solve Sudoku
        if (solveSudoku(puzzle, 0, 0)) {
            System.out.println("Solved Sudoku:");
            printBoard(puzzle);
        } else {
            System.out.println("No solution exists!");
        }
    }
}
