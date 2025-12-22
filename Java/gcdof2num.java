import java.util.*;;

public class gcdof2num {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.println("Enter the first number: ");
        int n1 = s.nextInt();
        System.out.println("Enter the second number: ");
        int n2 = s.nextInt();
        System.out.println("the gcd of" + n1 + " and " + n2 + " is :" + gcd(n1, n2));
s.close();
    }

    public static int gcd(int n1,int n2) 
    {
        while(n1!=n2)
        {
        if(n1>n2)
        {
            n1=n1-n2;
        }
        else{
            n2=n2-n1;
        }
    }
        return n1;
    }
}
