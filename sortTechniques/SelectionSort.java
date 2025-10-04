package sortTechniques;

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr = {12,34,56,7,43};
        for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[j]<arr[i]){
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        for (int i : arr) {
           System.out.println(i); 
        }
    }
    
}
