import java.util.Scanner;

public class ifelseif {

    public static void main(String[] args) {
        int marks;
        System.out.print("enter marks :");
        Scanner obj = new Scanner(System.in);
        marks = obj.nextInt();
        if (marks >= 60 && marks <= 100)
         {
            System.out.print("First Divison");
        } 
        else if (marks >= 45 && marks < 60) 
        {
            System.out.print("second division");
        } else if (marks >= 33 && marks < 45) 
        {
            System.out.print("third divison");
        } else 
        {
            System.out.print("fail");
        }
        obj.close();

    }

}
