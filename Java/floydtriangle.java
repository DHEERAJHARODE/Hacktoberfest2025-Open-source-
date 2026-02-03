import java.util.Scanner;

public class floydtriangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter number of rows you want");
        int n = sc.nextInt();
        int number=1;
        for(int i = 1 ;i <=n ;i++){
            for(int j=1;j<=i;j++){
                System.out.print(number +" ");
                number = number+1;
            }System.out.println();
        }
    }
}
