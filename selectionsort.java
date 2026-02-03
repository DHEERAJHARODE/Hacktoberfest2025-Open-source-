import java.util.*;
public class selectionsort {
    public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);
     int ar[]=new int[8];
     System.out.println("ENTER THE ELEMENTS");
     for(int i=0;i<8;i++)
     {
        ar[i]=sc.nextInt();
     }
     int min;min=0;
     for(int i=0;i<7;i++)
     {
        min=i;   
        
        for(int j=i+1;j<6;j++)
        {
            if(ar[j]<ar[min])
            {
            min=j;
            }
        }
    
    int temp=ar[min];
    ar[min]=ar[i];
    ar[i]=temp;
     }
     for(int i=0;i<8;i++)
     {
        System.out.print(ar[i]+ " ");
     }
    }

}
