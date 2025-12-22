import java.util.Scanner;

public class ifelse_condition {
    public static void main(String[] args) {

        int pwd; 
        System.out.print("enter the password");
        Scanner obj = new Scanner(System.in);
        pwd = obj.nextInt();
        if (pwd == 4321)
        {
            System.out.println("my name - Patel Yash");
            System.out.println("my age 19");
            System.out.print("my address-near bus station , dhoraji-360410");
        } 
        else
         {
            System.out.print("Soory! wrong password...");

        }
        obj.close();

    }

}
