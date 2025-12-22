import java.util.Scanner;

public class dowhile_loop {
    
    public static void main(String[] args) 
    {
        int num;
        System.out.print("enter any number");
        Scanner s= new Scanner(System.in);

        num=s.nextInt();
            do
            {
                System.out.println(num+ " Do coding");        
                ++num;
            }
            while(num<=10);
    s.close();
    }

}
