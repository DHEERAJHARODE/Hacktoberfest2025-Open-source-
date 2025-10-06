// Problem: Rat in a Maze
// Description: Find all possible paths for a rat to move from top-left to bottom-right
// of an n x n maze. The rat can move only right or down (or in 4 directions if allowed).
// '1' represents open path, '0' represents blocked cell.

import java.util.ArrayList;

class RatInMaze {
    static int N = 4; // Size of the maze

    // Utility function to check if cell is safe to move
    static boolean isSafe(int maze[][], int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
    }

    // Recursive function to solve the maze
    static boolean solveMazeUtil(int maze[][], int x, int y, int sol[][]) {
        // If destination is reached
        if (x == N - 1 && y == N - 1) {
            sol[x][y] = 1;
            printSolution(sol);
            sol[x][y] = 0; // Backtrack for other solutions
            return true;   // To print all solutions
        }

        if (isSafe(maze, x, y)) {
            sol[x][y] = 1;

            // Move right
            solveMazeUtil(maze, x, y + 1, sol);
            // Move down
            solveMazeUtil(maze, x + 1, y, sol);
            // Move left
            solveMazeUtil(maze, x, y - 1, sol);
            // Move up
            solveMazeUtil(maze, x - 1, y, sol);

            sol[x][y] = 0; // BACKTRACK
        }
        return false;
    }

    // Function to print solution matrix
    static void printSolution(int sol[][]) {
        System.out.println("Path:");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(sol[i][j] + " ");
            System.out.println();
        }
        System.out.println();
    }

    // Main function
    public static void main(String args[]) {
        int maze[][] = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {0, 1, 0, 0},
            {1, 1, 1, 1}
        };

        int sol[][] = new int[N][N];

        if (!solveMazeUtil(maze, 0, 0, sol))
            System.out.println("No solution exists");
    }
}
