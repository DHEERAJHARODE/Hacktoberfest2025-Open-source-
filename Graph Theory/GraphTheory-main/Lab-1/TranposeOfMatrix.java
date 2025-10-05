import java.util.Arrays;
import java.util.Scanner;

public class TranposeOfMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the Number of Rows: ");
        int rows = sc.nextInt();
        
        System.out.print("Enter the Number of Columns: ");
        int columns = sc.nextInt();
        
        int[][] matrix = new int[rows][columns];
        System.out.println("Enter the Elements of the Matrix:");
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print("Enter the value in matrix[" + i + "][" + j + "] = ");
                matrix[i][j] = sc.nextInt();
            }
        }

        System.out.println("\nOriginal Matrix:");
        for (int i = 0; i < rows; i++) {
            System.out.println(Arrays.toString(matrix[i]));
        }

        // Create a new matrix for transpose
        int[][] transpose = new int[columns][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }

        System.out.println("\nTransposed Matrix:");
        for (int i = 0; i < columns; i++) {
            System.out.println(Arrays.toString(transpose[i]));
        }

        sc.close();
    }
}
