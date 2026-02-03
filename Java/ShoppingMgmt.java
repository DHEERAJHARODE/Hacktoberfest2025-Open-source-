//This file contains Shopping management system code
import java.util.ArrayList;
import java.util.Scanner;

class BalanceOutException extends Exception {
    BalanceOutException(String str) {
        System.out.println(str);
    }
}

class ShoppingMgmtOp {
    Scanner scan = new Scanner(System.in);
    String name;
    int age;
    String gender;
    private double wallet_balance;
    private double totalBill;

    double price;
    ArrayList<Double> prices = new ArrayList<>();
    ArrayList<String> items = new ArrayList<>();
    ArrayList<Integer> quantity = new ArrayList<>();

    /* ***************This will create User ************/
    public void createUser(String name, int age, String gender) {

        this.name = name;
        this.age = age;
        this.gender = gender;
        this.setBalance(1);
    }

    public void setBalance(int flag) {

        if (flag != 0) {
            System.out.println(
                    "Hello " + this.name + ",thank you for choosing us" + "\nEnter Amount into wallet to proceed for Shopping.");
            this.wallet_balance = scan.nextDouble();
        } else {
            System.out.println("Hello " + name + "\nEnter extra  Amount into wallet to proceed for Shopping.");
            double amt = scan.nextDouble();
            this.wallet_balance += amt;
        }
    }

    public void purchaseItem() {
        int i = 0;
        String wish = "y";
        while (wish.equals("y")) {

            System.out.println("Enter your item's name : ");
            String item = scan.next();
            items.add(i, item);

            System.out.println("Enter your item's Quantity: ");
            int qty = scan.nextInt();
            quantity.add(i, qty);

            System.out.println("Enter your item's price : ");
            price = scan.nextDouble();
            price = (price * qty);
            prices.add(i, price);

            this.totalBill += prices.get(i);
            i++;
            System.out.println("Do you want to continue Purchase? (Yes-y||No-n)");
            String w = scan.next();
            if (w.equals("n")) {
                wish = "n";

            }
        }
        billingSystem();

    }

    public void billingSystem() {
        if (totalBill > wallet_balance) {
            double exc = totalBill - wallet_balance;
            try {
                throw new BalanceOutException("Your Balance is less than the Total Balance");
            } catch (BalanceOutException e) {
                System.out.println(
                        "Enter " + exc + " to your Wallet or remove few items equivalent to the excess amount ");
                while (true) {
                    System.out
                            .println("1.Enter '1' to Enter Amount\n2.Enter '2' to remove item\n3.Cancel Transaction\n");
                    int ch = scan.nextInt();

                    switch (ch) {
                        case 1:

                            setBalance(0);
                            exc = totalBill - wallet_balance;
                            display();
                            break;
                        case 2:
                            System.out.println("Remove Item from the list to adjust: " + exc);
                            display();
                            removeItem();
                            break;
                        case 3:
                            System.exit(0);

                        default:
                            System.out.println("Wromg Choice ");
                    }
                }
            }
        } else {
            display();
        }
    }

    public void removeItem() {
        System.out.println("Enter which Product you want to remove");
        int i = scan.nextInt();
        System.out.println("Enter Quantity you want to Remove");
        int j = scan.nextInt();
        double unitPrice = prices.get(i) / quantity.get(i);

        totalBill = totalBill - (j * unitPrice);
        quantity.set(i, (quantity.get(i) - j));
        prices.set(i, (quantity.get(i)) * unitPrice);
        System.out.println("Your current wallet Balance " + wallet_balance);
        if (quantity.get(i) == 0) {
            items.remove(i);
            quantity.remove(i);
            prices.remove(i);
        }
        display();
    }

    public void display() {
        System.out.print("\n\t\tItem No.\t\tName\t\tQuantity\tUnit Price\t\tRate \n");
        for (int i = 0; i < items.size(); i++) {
            double unitPrice = prices.get(i) / quantity.get(i);
            System.out.print("\n\t\t\t" + i + "\t\t" + items.get(i) + "\t\t" + quantity.get(i) + "\t\t" + unitPrice
                    + "\t\t\t" + prices.get(i));
        }
        System.out.println("\n\t\t\t\t\t\t\t\t\t\t\t\t\tTotal Bill : " + totalBill);
        if (totalBill <= wallet_balance) {
            System.out.println("THANK YOU FOR SHOPPING!!!!\nHAVE A NICE DAY :)");
            System.exit(0);
        }
    }

}

public class ShoppingMgmt {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        ShoppingMgmtOp ob = new ShoppingMgmtOp();
        System.out.println("Please Reegister Yourself for Shopping....");
        System.out.print("Enter Your Name : \n");
        String name = scan.nextLine();
        System.out.println("Enter Your age : \n");
        int age = scan.nextInt();
        System.out.println("Enter Gender :\n");
        String gen = scan.next();
        ob.createUser(name, age, gen);
        ob.purchaseItem();

    }
}
