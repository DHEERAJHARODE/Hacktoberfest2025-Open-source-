import java.util.Scanner;  

public class SunnyNumberExample2  

{  

//user-defined function that determines all the sunny numbers  

public static boolean isSunnyNumber(int number)   

{  

//determines the square root of number+1 using Math.sqrt() method  

if(Math.sqrt(number+1)%1 == 0)  

return true;  

else   

return false;  

}  

//driver code  

public static void main(String args[])   

{  

//lr is lower range and ur is upper range  

int lr = 0, ur = 0;  

Scanner scan = new Scanner(System.in);  

System.out.print("Enter lower range: ");  

//reads an integer (lr) from the user  

lr = scan.nextInt();  

System.out.print("Enter upper range: ");  

//reads an integer (ur) from the user  

ur = scan.nextInt();  

System.out.println("The Sunny number from "+ lr + " to "+ ur+" are: ");  

for(int i=lr; i<=ur; i++)   

{  

//calling user-defined number  

if(isSunny(i))  

System.out.print(i +" ");  

}  

}  

}  
