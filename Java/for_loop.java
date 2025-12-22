import java.util.Scanner;

public class for_loop {

    public static void main(String[] args) {
        
    int num;
    System.out.print("enter any number ");
    Scanner s=new Scanner(System.in);
    num=s.nextInt();
    for(int i=1;i<=10;i++)
    {
        System.out.println(num*i);
    }
s.close();
    }
}
