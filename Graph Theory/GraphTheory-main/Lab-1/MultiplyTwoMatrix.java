import java.util.Arrays;
import java.util.Scanner;

public class MultiplyTwoMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter rows and columns of first matrix:");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        System.out.println("Enter rows and columns of second matrix:");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();
        if (c1 != r2) {
            System.out.println("Matrix multiplication not possible due to incompatible dimensions.");
            sc.close();
            return;
        }

        int[][] m1 = new int[r1][c1];
        System.out.println("Enter the Elements of the Matrix1:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                System.out.print("Enter the value in matrix[" + i + "][" + j + "] = ");
                m1[i][j] = sc.nextInt();
            }
        }

        int[][] m2 = new int[r2][c2];
        System.out.println("Enter the Elements of the Matrix2:");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                System.out.print("Enter the value in matrix[" + i + "][" + j + "] = ");
                m2[i][j] = sc.nextInt();
            }
        }

        int[][] m3 = new int[r1][c2];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }

        System.out.println("\nMatrix1:");
        for (int i = 0; i < r1; i++) {
            System.out.println(Arrays.toString(m1[i]));
        }

        System.out.println("\nMatrix2:");
        for (int i = 0; i < r2; i++) {
            System.out.println(Arrays.toString(m2[i]));
        }
        
        System.out.println("\nMatrix3:");
        for (int i = 0; i < r1; i++) {
            System.out.println(Arrays.toString(m3[i]));
        }

        sc.close();
    }
}