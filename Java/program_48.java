import java.util.Scanner;

abstract class bank 
{
    public String Name = "dream bank";
    public String IFSC = "dream123";

    public void bankdetail() 
    {
        System.out.println("Bank Name: " + Name + "Bank IFSC Code: " + IFSC);
    }

    // password
    abstract void deposit();

    abstract void withdraw();

    abstract void checkbal();
}

class bankservice extends bank 
{
    private double bal = 5000;
    private int pwd;
    public double money;

    public void deposit() 
    {
        System.out.println("enter the password");
        Scanner s = new Scanner(System.in);
        pwd = s.nextInt();

        if (pwd == 123) 
        {
            System.out.println("enter deposit amount");
            money = s.nextDouble();
            bal = bal + money;
            System.out.println("Deposit amount: " + money);
            System.out.println("Total balance: " + bal);
        } else {
            System.out.println("Invalid password...");
        }
        s.close();
    }

    public void withdraw() {
        System.out.println("enter the password");
        Scanner s = new Scanner(System.in);
        pwd = s.nextInt();

        if (pwd == 123) 
        {
            System.out.println("enter withdrawn amount");
            money = s.nextDouble();
            bal = bal - money;
            System.out.println("withdrawn money : " + money);
            System.out.println("Total balance: " + bal);
        } else 
        {
            System.out.println("Invalid password...");
        }
        s.close();
    }

    public void checkbal() {
        System.out.println("enter password");
        Scanner s = new Scanner(System.in);
        pwd = s.nextInt();
        if (pwd == 123) {
            System.out.println("total balance " + bal);
        } else {
            System.out.println("incorrect password...");
        }
        s.close();
    }
}

class customer 
{
    public static void main(String[] args) 
    {
        bankservice b = new bankservice();
        b.bankdetail();

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
        }
s2.close();
    }
}