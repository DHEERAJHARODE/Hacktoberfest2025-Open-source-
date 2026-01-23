import java.util.Scanner;

class ReverseString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Write something to reverse it: ");
        String s = sc.nextLine();
        System.out.println("Original String: " + s);
        
        // Initialize an empty string for the reversed result
        String reversedString = "";

        // Loop through the original string in reverse order
        for (int i = s.length() - 1; i >= 0; i--) {
            reversedString += s.charAt(i); // Append each character to the result
        }

        // Output the reversed string
        System.out.println("Reversed String: " + reversedString);
    }
}
