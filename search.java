 import java.util.*;
public class search{
  public static void main(String args[]){
    Scanner sc = new Scanner (System.in);
    System.out.println("Enter the no of rows");
    int rows = sc.nextInt();
    System.out.println("Enter the no of columns");
    int cols = sc.nextInt();
    
    int numbers[] [] = new int [rows] [cols];
    
    for(int i = 0;i<rows;i++){
      for(int j = 0;j<cols;j++){
        numbers[i] [j] = sc.nextInt();
      }
    }
    System.out.println("Enter the number which has to be found");
    int x = sc.nextInt();
    
    for(int i = 0;i<rows;i++){
      for(int j = 0;j<cols;j++){
       if( numbers[i] [j] == x){
         System.out.println(x + " found at index " +i+"," + "j");
       }else{
         System.out.println("Number not found");
       }
        
      }
    }
  }
}
