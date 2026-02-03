import java.util.*;  
 class Clockwise_Rotate  
 {  
   public static void main()  
   {  
     Scanner sc=new Scanner(System.in);  
     System.out.println("Enter the number of Rows");  
     int r=sc.nextInt();  
     System.out.println("Enter the number of Columns");  
     int c=sc.nextInt();  
     int arr[][]=new int[r][c];  
     System.out.println("Enter the elements of Matrix");  
     for(int i=0;i<r;i++)  
     {  
       for(int j=0;j<c;j++)  
       {          
         arr[i][j]=sc.nextInt();  
       }        
     }  
     System.out.println("Input Matrix Is:");  
     for(int i=0;i<r;i++)  
     {  
       for(int j=0;j<c;j++)  
       {          
         System.out.print(arr[i][j]+" ");  
       }  
       System.out.println("");       
     }  
     System.out.println("Matrix After Rotation Is:");  
     for(int j=0;j<c;j++)  
     {  
       for(int i=r-1;i>=0;i--)  
       {          
         System.out.print(arr[i][j]+"\t");  
       }  
       System.out.println(" ");       
     }  
   }  
 }  
