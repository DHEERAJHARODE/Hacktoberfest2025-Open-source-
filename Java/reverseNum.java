import java.util.*;
public class reverseNum {
    
    public static void main(String[] args) {
        
        Scanner s= new Scanner(System.in);
        int arr[]=new int[10];
        System.out.println("Enter the array :");
        for(int i=0;i<10;i++)
        {
            arr[i]=s.nextInt();
        }
        System.out.println("the reverse of an array is: ");
        for(int i=10-1;i>=0;i--)
        {
            System.out.println(arr[i]);
        }
        s.close();
    }
}
