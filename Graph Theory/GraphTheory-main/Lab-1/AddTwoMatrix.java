import java.util.Arrays;
import java.util.Scanner;

public class AddTwoMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the Number of Rows: ");
        int rows = sc.nextInt();
        
        System.out.print("Enter the Number of Columns: ");
        int columns = sc.nextInt();
        
        int[][] m1 = new int[rows][columns];
        System.out.println("Enter the Elements of the Matrix1:");
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print("Enter the value in matrix[" + i + "][" + j + "] = ");
                m1[i][j] = sc.nextInt();
            }
        }

        int[][] m2 = new int[rows][columns];
        System.out.println("Enter the Elements of the Matrix2:");
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print("Enter the value in matrix[" + i + "][" + j + "] = ");
                m2[i][j] = sc.nextInt();
            }
        }

        int[][] m3 = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                m3[i][j] = m1[i][j] + m2[i][j];
            }
        }

        System.out.println("\nMatrix1:");
        for (int i = 0; i < rows; i++) {
            System.out.println(Arrays.toString(m1[i]));
        }

        System.out.println("\nMatrix2:");
        for (int i = 0; i < rows; i++) {
            System.out.println(Arrays.toString(m2[i]));
        }
        
        System.out.println("\nMatrix3:");
        for (int i = 0; i < rows; i++) {
            System.out.println(Arrays.toString(m3[i]));
        }

        sc.close();
    }
}
