package sortTechniques;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {12,34,56,7,43};
        for(int i=0;i<arr.length;i++){
            for(int j=i;j<arr.length-1;j++){
                if(arr[i]>arr[i+1]){
                int temp;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }}
        }
        for (int i : arr) {
            System.out.println(i); 
         }
    }
}
