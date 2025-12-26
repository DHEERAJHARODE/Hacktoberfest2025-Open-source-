import java.util.Scanner;
public class allDevisors {
    public static void main (String [] args){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number ");
        int number = sc.nextInt();

        for( int i = 1; i <= number; i++){
            if ( number % i == 0){
                System.out.print( " " + i);
            }
        }

    }
    
}
