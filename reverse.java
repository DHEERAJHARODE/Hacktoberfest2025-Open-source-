// Java Program to Reverse a string
import java.io.*;
import java.util.Scanner;
class Main {
    public static void main (String[] args) {
     String str= "reverse", str1="";
        char ch;
      
      System.out.print("Original word: ");
      System.out.println("reverse");
      
      for (int i=0; i<str.length(); i++)
      {
        ch= str.charAt(i); //extracts each character
        str1= ch+str1; //adds each character in front of the existing string
      }
      System.out.println("Reversed word: "+ str1);
    }
}
