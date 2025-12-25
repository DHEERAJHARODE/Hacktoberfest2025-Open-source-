public class BinarySearch {

  public static void main(String args[]) {  
        int arr[] = {10,20,30,40,50};  
        int key = 30;  
        int last = (arr.length) - 1;  
        
        int result = binarySearch(arr, 0, last, key);  
        
        if (result == -1)  
            System.out.println("Element is not found!");  
        else  
            System.out.println("Element is found at index: " + result);  
    }
  
  public static int binarySearch(int arr[], int first, int last, int key){  
        if (last >= first){  
            int mid = first + (last - first) / 2;  
            
            if (arr[mid] == key){  
              return mid;  
            } 
            
            if (arr[mid] > key){  
              return binarySearch(arr, first, mid-1, key);
            
            }else{  
              return binarySearch(arr, mid+1, last, key);
            }  
        } 
        return -1;  
    }  

}
