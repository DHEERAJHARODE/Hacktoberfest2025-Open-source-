import java.util.*;
class special_twodigit_number
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number");
        int n=sc.nextInt();
        int e=n;
        int s=0,p=1;
        while(n!=0)
        {
            int d=n%10;
            s=s+d;
            p=p*d;
            n=n/10;
        }
        if((s+p)==e)
        {
            System.out.println("The number is special digit");
        }
        else
        {
            System.out.println("The number is not special digit");
        }
    }
}
