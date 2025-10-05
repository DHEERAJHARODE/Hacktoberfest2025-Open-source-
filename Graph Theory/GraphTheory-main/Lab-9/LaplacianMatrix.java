//  Prob. 1 Given a undirected Graph of N vertices 1 to N and M edges in form of 2D array arr[][] whose every 
// row consists of two numbers X and Y which denotes that there is an edge between X and Y, now write a 
// program to create Laplacian matrix. 
 
// The Laplacian matrix (also known as graph Laplacian, admittance matrix, Kirchhoff matrix or discrete 
// Laplacian) is a matrix representation of a graph. To find the Laplacian matrix first, find adjacency matrix 
// and degree matrix of a graph as the formula for the Laplacian matrix is as follows: 
// Laplacian matrix = Degree matrix – Adjacency matrix 
 
// Input: N = 5, M = 4, arr[][] = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 5 } }  
// output:  
// [ 2 -1  0  0 -1, 
//  -1  2 -1  0  0, 
//   0 -1  1  0  0, 
//   0  0  0  1 -1, 
//  -1  0  0 -1  2 
// ]

public class LaplacianMatrix {
    public static void main(String[] args) {
        int N = 5; // number of vertices
        int M = 4; // number of edges
        int[][] arr = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 5} };
        int[][] laplacianMatrix = new int[N][N];

        // Construct adjacency matrix
        for (int[] edge : arr) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            laplacianMatrix[u][v] = -1;
            laplacianMatrix[v][u] = -1;
            
            laplacianMatrix[u][u] += 1;
            laplacianMatrix[v][v] += 1;
        }

        System.out.println("\nLaplacian Matrix:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(laplacianMatrix[i][j] + "     ");
            }
            System.out.println();
        }

    }
}

// public class LaplacianMatrix {
//     public static void main(String[] args) {
//         int N = 5; // number of vertices
//         int M = 4; // number of edges
//         int[][] arr = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 5} };
//         int[][] adjacencyMatrix = new int[N][N];
//         int[][] degreeMatrix = new int[N][N];
//         int[][] laplacianMatrix = new int[N][N];

//         // Construct adjacency matrix
//         for (int[] edge : arr) {
//             int u = edge[0] - 1;
//             int v = edge[1] - 1;
//             adjacencyMatrix[u][v] = 1;
//             adjacencyMatrix[v][u] = 1;
//         }

//         System.out.println("\nAdjacency Matrix:\n");
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 System.out.print(adjacencyMatrix[i][j] + "  ");
//             }
//             System.out.println();
//         }

//         // Construct degree matrix
//         for (int[] edge : arr) {
//             int u = edge[0] - 1;
//             int v = edge[1] - 1;
//             degreeMatrix[u][u] += 1;
//             degreeMatrix[v][v] += 1;
//         }

//         System.out.println("\nDegree Matrix:\n");
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 System.out.print(degreeMatrix[i][j] + " ");
//             }
//             System.out.println();
//         }

//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 laplacianMatrix[i][j] = degreeMatrix[i][j] - adjacencyMatrix[i][j];
//             }
//         }

//         System.out.println("\nLaplacian Matrix:\n");
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 System.out.print(laplacianMatrix[i][j] + "     ");
//             }
//             System.out.println();
//         }

//     }
// }
