import java.util.*;
import java.io.*;
import java.lang.*;
class GFG 
{ 
    

    static void maxDiff(int arr[], int n)
    {
      int first=arr[0];
      int count=1;
      for(int i=1;i<n;i++){
      if(first==arr[i]){
          count++;
      }else{
          System.out.print(first+" ");
          System.out.print(count);
          count=1;
          first=arr[i];
          System.out.print(" ");
      }  
      
      }
      System.out.print(first+" ");
          System.out.print(count);
    }


    public static void main(String args[]) 
    { 
       int arr[] = {40,50,50,50}, n = 4;

       maxDiff(arr, n);

    } 

}
