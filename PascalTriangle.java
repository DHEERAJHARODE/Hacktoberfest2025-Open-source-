import java.util.Scanner;
public class Triangle
{
 
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows: ");
 
        int rows = sc.nextInt();        
        for (int i= 1; i&lt;= rows ; i++)
        {
            for (int j=i; j &lt;rows ;j++)            
        {
                System.out.print(" ");
            }
            for (int k=1; k&lt;=i;k++) { System.out.print("*"); } System.out.println(""); } for (int i=rows; i&gt;=1; i--)
        {
            for(int j=i; j&lt;=rows;j++)
            {
                System.out.print(" ");
            }
            for(int k=1; k&lt;i ;k++) 
            {
                System.out.print("*");
            }
            System.out.println("");
 
        }
        sc.close();
    }
}
