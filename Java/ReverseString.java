import java.util.Scanner;

public class ReverseString {

    /*
     * This method takes a string as input
     * and returns the reversed version of it.
     * Example:
     *   Input  : "hello"
     *   Output : "olleh"
     */
    public static String reverse(String input) {
        if (input == null) {
            return null;
        }

        // Using StringBuilder for efficient reversal
        return new StringBuilder(input).reverse().toString();
    }

    public static void main(String[] args) {

        // Scanner is used to take user input from the console
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string to reverse: ");
        String userInput = sc.nextLine();   // Taking complete line as input

        String reversed = reverse(userInput);  // Calling the reverse method

        System.out.println("Reversed String: " + reversed);

        sc.close(); // Closing the scanner (good practice)
    }
}

