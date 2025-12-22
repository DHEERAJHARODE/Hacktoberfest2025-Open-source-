import java.util.Arrays;
import java.util.Scanner;

public class array3 {

    public static void main(String[] args) {
        int a[] = new int[5];
        System.out.print("enter the array elements\n");
        Scanner p = new Scanner(System.in);
        for (int i = 0; i < 5; i++) 
        {
            a[i] = p.nextInt();
        }
        Arrays.sort(a);
        System.out.print("\n sorted array elements are\n");
        for (int b : a) {
            System.out.println(b + " ");
        }
        p.close();
    }
}