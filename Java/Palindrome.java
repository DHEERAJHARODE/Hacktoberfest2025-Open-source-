import java.util.*;
class Palindrome
{
    public static void main(String args[])
    {
        int a,b,c,rev=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter A Number-");
        a=sc.nextInt();
        b=a;
        while(b>0)
        {
            c=b%10;
            rev=rev*10+c;
            b=b/10;
        }
        if(rev==a)
        {
            System.out.println("The Given Number "+a+" is a Palindrome Number.");
        }
        else
        {
            System.out.println("The Given Number "+a+" is not a Palindrome Number.");
        }
    }
}
