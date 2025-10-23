import java.util.Scanner;

public class BinaryToDecimal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take binary number input from user
        System.out.print("Enter a binary number: ");
        String binary = sc.nextLine();

        // Convert binary to decimal using built-in method
        int decimal = Integer.parseInt(binary, 2);

        // Display result
        System.out.println("Decimal equivalent: " + decimal);

        sc.close();
    }
}
