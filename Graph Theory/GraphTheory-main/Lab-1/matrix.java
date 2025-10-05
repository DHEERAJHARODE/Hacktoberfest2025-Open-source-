import java.util.Arrays;
import java.util.Scanner;

public class matrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Number of Rows: ");
        int rows = sc.nextInt();
        System.out.println("Enter the Number of Columns: ");
        int columns = sc.nextInt();
        int[][] matrix = new int[rows][columns];
        System.out.println("Enter the Elements of the Matrix: ");
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                System.out.println("Enter the value in matrix["+i+"]["+j+"] = ");
                matrix[i][j] = sc.nextInt();    
            }
        }

        for (int i = 0; i<rows; i++){
           System.out.println(Arrays.toString(matrix[i]));
        }
        sc.close();
    }
}
