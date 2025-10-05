import java.util.Scanner;

public class FindRankOfMatrix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final double EPS = 1e-10;

        System.out.print("Enter matrix size n: ");
        int n = scanner.nextInt();

        double[][] mat = new double[n][n];
        System.out.println("Enter the matrix (row by row):");
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                mat[i][j] = scanner.nextDouble();
            }
        }

        System.out.println("\n Before Matrix : \n");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();

        int rank = n;
        for (int row = 0; row < rank; row++) {
            if (Math.abs(mat[row][row]) > EPS) {
                for (int col = 0; col < n; col++) {
                    if (col != row) {
                        double factor = mat[col][row] / mat[row][row];
                        for (int i = 0; i < n; i++) {
                            mat[col][i] -= factor * mat[row][i];
                        }
                    }
                }
            } else {
                boolean reduce = true;
                for (int i = row + 1; i < n; i++) {
                    if (Math.abs(mat[i][row]) > EPS) {
                        double[] temp = mat[row];
                        mat[row] = mat[i];
                        mat[i] = temp;
                        reduce = false;
                        break;
                    }
                }

                if (reduce) {
                    rank--;
                    for (int i = 0; i < n; i++) {
                        mat[i][row] = mat[i][rank];
                    }
                }

                row--;
            }
        }

        System.out.println("\n After Matrix : \n");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();

        System.out.println("Rank of the matrix is: " + rank);
        scanner.close();
    }
}
