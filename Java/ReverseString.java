// File name: ReverseString.java
import java.util.Scanner;

public class ReverseString {

    // Function to reverse a given string
    public static String reverseString(String str) {
        // Using StringBuilder to reverse the string
        return new StringBuilder(str).reverse().toString();
    }

    public static void main(String[] args) {
        // Step 1: Create Scanner object to read input from user
        Scanner sc = new Scanner(System.in);

        // Step 2: Prompt the user to enter a string
        System.out.print("Enter a string to reverse: ");
        String input = sc.nextLine(); // Read input

        // Step 3: Call the reverseString function
        String reversed = reverseString(input);

        // Step 4: Print the reversed string
        System.out.println("Reversed string: " + reversed);

        // Step 5: Close Scanner
        sc.close();
    }
}

/*
Example Usage:

Input:
    Enter a string to reverse: Hacktoberfest
Output:
    Reversed string: tsefrebotkcaH

Input:
    Enter a string to reverse: Hello World
Output:
    Reversed string: dlroW olleH
*/
