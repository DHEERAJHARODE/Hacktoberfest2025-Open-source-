import java.util.*;

public class ArrayToGraph {
    public static void main(String[] args) {
        int N = 5; // number of vertices
        int M = 4; // number of edges
        int[][] arr = { { 1, 2 }, { 2, 3 }, { 4, 5 } };
        int[][] matrix = new int[N][N];

        // Construct adjacency matrix
        for (int[] edge : arr) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        System.out.println("\nAdjacency Matrix:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        // Check if graph is connected
        boolean[] visited = new boolean[N];
        dfs(0, visited, matrix, N);

        boolean isConnected = true;
        for (boolean v : visited) {
            if (!v) {
                isConnected = false;
                break;
            }
        }

        System.out.println("\nGraph is " + (isConnected ? "Connected" : "Disconnected"));
    }

    // DFS function
    static void dfs(int node, boolean[] visited, int[][] matrix, int N) {
        visited[node] = true;
        for (int i = 0; i < N; i++) {
            if (matrix[node][i] == 1 && !visited[i]) {
                dfs(i, visited, matrix, N);
            }
        }
    }
}
