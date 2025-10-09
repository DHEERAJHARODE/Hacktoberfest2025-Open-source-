import java.util.Scanner;
class Calculator {

  
  public static void main(String args[]){

  int num1, num2, operation, result;
   
    System.out.println("Welcome to Calculator! \n Here you can perform the following operations \n Please! follow the commands for certain operations");

    System.out.println("Operation Menu \n1 for Addition \n 2 for Substraction \n 3 for Multiplication \n 4 for Division \n 5 for Modulas");

    System.out.print("Enter opertation :");
    Scanner sc = new Scanner(System.in);
    operation = sc.nextInt();

    switch(operation) {
     
     case 1 : 
        System.out.print("ADDITION \nEnter a number:");
        num1  = sc.nextInt();
        System.out.print("Enter a another number:");
        num2  = sc.nextInt();
        result = num1 + num2;
        System.out.println("The sum of "+ num1 +" & "+ num2 + " is:"+result);
        break;
        
     case 2 :
        System.out.print("SUBSTRACTION \n Enter a number:");
        num1  = sc.nextInt();
        System.out.print("Enter a another number:");
        num2  = sc.nextInt();
        result = num1 - num2;
        System.out.println("The sum of "+ num1 +" & "+ num2 + " is:"+result);
        break;
        
     case 3 : 
        System.out.print("MULTIPLICATION \n Enter a number:");
        num1  = sc.nextInt();
        System.out.print("Enter a another number:");
        num2  = sc.nextInt();
        result = num1 * num2;
        System.out.println("The sum of "+ num1 +" & "+ num2 + " is:"+result);
        break;
        
     case 4 : 
        System.out.print("DIVISION \n Enter a number:");
        num1  = sc.nextInt();
        System.out.print("Enter a another number:");
        num2  = sc.nextInt();
        result = num1 / num2;
        System.out.println("The sum of "+ num1 +" & "+ num2 + " is:"+result);
        break;
        
     case 5 : 
        System.out.print("MOD \n Enter a number:");
        num1  = sc.nextInt();
        System.out.print("Enter a another number:");
        num2  = sc.nextInt();
        result = num1 % num2;
        System.out.println("The sum of "+ num1 +" & "+ num2 + " is:"+result);
        break;
        
    
    }

    
  }

}