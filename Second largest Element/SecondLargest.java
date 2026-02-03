/*This program shows how to find the second largest element in array without using 
/sorting mechanism*/
import java.util.Scanner;
class SecondLargest{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int max =-1;
        int sec_max = -1; //represents no valid second max element found
        int n = sc.nextInt();
        int arr[] = new int[n];
//enter elements in array
 for(int i=0;i<n;i++){
     arr[i] = sc.nextInt();
 }
//display the array
for(int i=0;i<n;i++){
    System.out.print(arr[i]+"\t");
}
//first find the maximum in array
for(int i=0;i<n;i++){
    if(max== -1 || arr[i]>arr[max]){
         max = i;
    }
}
for (int i = 0; i < n; i++) {
    if(i !=max){
        if(sec_max == -1 || arr[i]>arr[sec_max]){
                sec_max = i;
        }
    }
}
if(sec_max == -1 || arr[sec_max]==arr[max]){
    System.out.println("NO SECOND MAX FOUND");
}
else{
System.out.println("The second largest element is : "+ arr[sec_max]);
}
    }
}
