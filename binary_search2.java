//Alternative Method for binary search

public class Search{
    void sort(int [] arr){
        int length = arr.length;
        for(int i = 0; i <length -1; i++){
            int lowest = i;
            for(int j = i+1; j <length; j++){
                if(arr[j] < arr[lowest]){
                    lowest = j;
                }
            
        }
        int temp = arr[lowest];
        arr[lowest] = arr[i];
        arr[i] = temp;
        }
    }

    int binary(int [] arr, int num){

        sort(arr);
        int first = 0;
        int last = arr.length - 1;

        while(first<=last){
        int mid = (first + last) / 2;
        if(arr[mid] == num){
            return mid;
        }else if(arr[mid] > num){
            last = mid - 1;
        }else{
            first = mid+1;
        }
    }
    return -1;
    }
    public static void main(String [] arrs){
        Search search = new Search();
        int [] arr1 = {1,4,3,5,68,9};
        int ele = 9;

        int find = search.binary(arr1, ele);
        System.out.println("The index we found the element is: " + find);
    }









}