import java.util.*;
class palindrome_no 
{
    public static void main(String[] args) 
    {
    Scanner in=new Scanner(System.in);
    int n, p=0, rev=0;
    System.out.println("Enter a number of your choice.");
    n=in.nextInt();
    p=n;
    while(n>0)
    {
        rev=rev*10+(n%10);
        n=n/10;
    }
    if(rev==p) 
    System.out.println(p+" is a Palindrome number");
    else 
    System.out.println(p+" is not a palindrome number");
    }
}