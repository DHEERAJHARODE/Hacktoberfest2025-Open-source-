package Maths;

public class trailing_zeros_in_factorial {
    static int fact(int n)
    {
        int res=0;
        for(int i=5;i<=n;i=i*5)
        {
            res=res+n/i;
        }
        return res;
    }
    public static void main(String args[])
    {
        System.out.println(fact(20));
    }

}
