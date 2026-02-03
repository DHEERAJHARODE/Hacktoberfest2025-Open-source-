import java.util.Arrays;
import java.util.Scanner;

public class sorting {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int size=sc.nextInt();
        int[] arr=new int[size];
        for (int a=0;a<size;a++){
            arr[a]=sc.nextInt();
        }
       bubblesort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void bubblesort(int [] arr){
        boolean swapped;
        for(int i=0;i<= arr.length;i++){
            swapped = false;
            for(int j=1;j< arr.length-i;j++){
                if(arr[j]<arr[j-1]){
                    int temp =arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                    swapped = true;
                }
            }
            if(!swapped){
                break;
            }
        }
    }
}
