import java.util.*;
public class increasingFactors {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enter the number");
        int n=s.nextInt();
        int div=2;

        while(n>1)
        {
            if(n%div==0)
            {
                System.out.print(div+",");
                n=n/div;
            }
            else{
                div++;
            }
        }
        s.close();
    }
}
