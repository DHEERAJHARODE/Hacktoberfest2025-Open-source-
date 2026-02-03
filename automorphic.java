import java.util.*;
class automorphic
{
    public static void main()
    { 
        Scanner sc=new Scanner(System.in);
        System.out.println("enter a number");
        int num=sc.nextInt();
        int num1=num;
        int flag=0,qum=num*num;
        while(num!=0)
        {
            int d= num%10;
            int d1=qum%10;
            if(d!=d1)
            flag=1;
            num=num/10;
            qum=qum/10;
        }
        if(flag==0)
           System.out.println(" it is an automorphic number");
        else
           System.out.println(" not an automorphic number");
        }
    }
    
        
