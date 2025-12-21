package com.example.BinarySearch;

public class OrderAgnostic {

    public static void main(String[] args) {

        int [] arr1 = {1,2,3,4,5,6,8,10};
        int [] arr2 = {10,8,6,5,4,3,2,1};

        int target1 = 5;
        int target2 = 8;

    int ans1 = OrderAgnosticBinarySearch(arr1,target1);
    int ans2 = OrderAgnosticBinarySearch(arr2,target2);

        System.out.println("The target in the asc sorted array is found at : "+ ans1);
        System.out.println("The target in the desc sorted array is found at : "+ans2);


    }

    static int OrderAgnosticBinarySearch(int [] arr, int target ){
        int start = 0 ;
        int end = arr.length-1;

        boolean isDesc = arr[start]>arr[end];


        while(start<=end){

            int mid = start + (end-start)/2;

            if(isDesc){

                if(target<arr[mid]){
                    start = mid +1;
                }
                else if(target>arr[mid]){
                    end = mid-1;
                }
                else{
                    return mid;
                }
            }
            else{
                if(target>arr[mid]){
                    start = mid+1;
                }else if(target<arr[mid]){
                    end = mid -1;
                }
                else{
                    return mid;
                }
            }
        }


        return -1;

    }
}
