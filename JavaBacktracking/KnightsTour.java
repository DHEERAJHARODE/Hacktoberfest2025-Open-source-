// Problem: Knight's Tour
// Description: Move a knight on an n x n chessboard so that it visits every square exactly once.
// Uses backtracking to find one possible solution.

class KnightsTour {
    static int N = 8; // Chessboard size

    // Utility function to print board
    static void printSolution(int sol[][]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.printf("%2d ", sol[i][j]);
            System.out.println();
        }
        System.out.println();
    }

    // Check if x,y are valid moves
    static boolean isSafe(int x, int y, int sol[][]) {
        return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
    }

    // Recursive utility function
    static boolean solveKTUtil(int x, int y, int movei, int sol[][], int xMove[], int yMove[]) {
        if (movei == N * N)
            return true;

        for (int k = 0; k < 8; k++) {
            int nextX = x + xMove[k];
            int nextY = y + yMove[k];
            if (isSafe(nextX, nextY, sol)) {
                sol[nextX][nextY] = movei;
                if (solveKTUtil(nextX, nextY, movei + 1, sol, xMove, yMove))
                    return true;
                sol[nextX][nextY] = -1; // BACKTRACK
            }
        }
        return false;
    }

    static void solveKT() {
        int sol[][] = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                sol[i][j] = -1;

        // Knight moves
        int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

        sol[0][0] = 0; // Start from top-left corner

        if (!solveKTUtil(0, 0, 1, sol, xMove, yMove)) {
            System.out.println("Solution does not exist");
        } else {
            printSolution(sol);
        }
    }

    public static void main(String args[]) {
        solveKT();
    }
}
