import java.util.Scanner;

public class add {
    public static void main(String[] args) {
        
        int a,b,c;
        System.out.print("enter two numbers: ");
        Scanner s=new Scanner(System.in);
        
        a=s.nextInt();
        b=s.nextInt();

        c=a+b;

        System.out.print("sum of two numbers: "+c);
        s.close();
    }
    
}
