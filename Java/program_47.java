
// small project for banking system  //
import java.util.Scanner;

class bank {
    private double bal = 5000;
    private int pwd;

    public void deposit() 
    {
        double money = 0;
        System.out.println("enter the amount");
        Scanner s3 = new Scanner(System.in);
        money = s3.nextInt();
        System.out.println("enter the password");
        Scanner s = new Scanner(System.in);
        pwd = s.nextInt();
        if (pwd == 123) 
        {
            bal = bal + money;
            System.out.println("deposited money " + money);
            System.out.println("total balance " + bal);
        } 
        else 
        {
            System.out.println("incorrect password...");
        }
        s.close();
        s3.close();
    }

    public void withdraw() 
    {
        double money = 0;
        System.out.println("enter the amount");
        Scanner s3 = new Scanner(System.in);
        money = s3.nextInt();
        System.out.println("enter the password");
        Scanner s = new Scanner(System.in);
        pwd = s.nextInt();
        
        if (pwd == 123) 
        {
            bal = bal - money;
            System.out.println("withdrawn money " + money);
            System.out.println("total balance " + bal);
        } 
        else 
        {
            System.out.println("incorrect password...");
        }
        s.close();
        s3.close();
    }

    public void checkbal() 
    {
        System.out.println("enter password");
        Scanner s = new Scanner(System.in);
        pwd = s.nextInt();
        if (pwd == 123) 
        {
            System.out.println("total balance " + bal);
        } 
        else 
        {
            System.out.println("incorrect password...");
        }
        s.close();
    }

}

class customer 
{
    public static void main(String[] args) 
    {
        bank b = new bank();
        int ch;
        System.out.println("1. deposit");
        System.out.println("2. withdraw");
        System.out.println("3. check balance");

        System.out.println("enter your choice");
        Scanner s2 = new Scanner(System.in);
        ch = s2.nextInt();
        switch (ch) 
        {
            case 1:
                b.deposit();
                break;
            case 2:
                b.withdraw();
                break;
            case 3:
                b.checkbal();
                break;
            default:
                System.out.println("invalid choice");
                break;
        }
        s2.close();
    }
}
