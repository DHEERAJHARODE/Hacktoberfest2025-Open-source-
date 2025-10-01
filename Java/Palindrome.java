import java.util.Scanner;

public class PalindromeChecker {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take input from user
        System.out.print("Enter a word or number: ");
        String originalText = scanner.nextLine();

        // Normalize input (ignore case, remove spaces)
        String cleanedText = originalText.replaceAll("\\s+", "").toLowerCase();

        // Reverse the cleaned text
        String reversedText = new StringBuilder(cleanedText).reverse().toString();

        // Check palindrome condition
        if (cleanedText.equals(reversedText)) {
            System.out.println("✅ The input \"" + originalText + "\" is a palindrome.");
        } else {
            System.out.println("❌ The input \"" + originalText + "\" is not a palindrome.");
        }

        scanner.close();
    }
}
