import java.util.Scanner;

public class PrimeInterval {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the lower bound: ");
        int l = in.nextInt();
        System.out.print("Enter the upper bound: ");
        int u = in.nextInt();
        System.out.println("Prime numbers between " + l + " and " + u + " are: ");
        prime(l, u);
    }

    private static void prime(int l, int u) {
        for(int i=l;i<=u;i++){
            boolean flag=true;
            if(i==1 || i==0){
                continue;
            }
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                System.out.print(i + " ");
            }
        }
    }
}
