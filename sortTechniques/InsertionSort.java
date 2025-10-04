package sortTechniques;


public class InsertionSort {
    public static void main(String[] args) {
        int[] arr = {12,34,56,7,43};
        for(int i=0;i<4;i++){
            int j=i;
            while(j>=0 && arr[j-1]>arr[j]) {
                int temp;
                temp = arr[j-1];
                arr[j-1]  = arr[j];
                arr[j] = temp;
                j--;
            }      
      
        }
        for (int i : arr) {
            System.out.println(i); 
         }
    }  
}
