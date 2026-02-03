package Maths;

public class palindrome {
    static boolean palindrome(int n)
    {
        int a=0;
        int r=n%10;
        a=a+10*r;
        n=n/10;
        if(a==n)
        {
            return true;
        }
        else {
            return false;
        }
    }
    public static void main(String[] args) {
        System.out.println(palindrome(370));

    }
}
