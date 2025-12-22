import java.util.Scanner;

public class array2 {

    public static void main(String[] args) {

        int a[]=new int[5];
        System.out.print("enter the array elements");
        Scanner p=new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            
            a[i]=p.nextInt();
        }
        System.out.print("\n array elements are\n");
        for (int b : a) {
            
            System.out.println(b+" ");

        }
        p.close();
        
    }
    
}
