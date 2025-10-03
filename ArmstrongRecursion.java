import java.util.Scanner;

public class ArmstrongRecursion {   // class name matches file name

    // Function to count digits using recursion
    static int countDigits(int n) {
        if (n == 0) {
            return 0;
        }
        return 1 + countDigits(n / 10);
    }

    // Recursive function to calculate sum of powers of digits
    static int armstrongSum(int n, int power) {
        if (n == 0) {
            return 0;
        }
        int digit = n % 10;
        return (int) Math.pow(digit, power) + armstrongSum(n / 10, power);
    }

    // Function to check Armstrong number
    static boolean isArmstrong(int n) {
        int digits = countDigits(n);
        int sum = armstrongSum(n, digits);
        return sum == n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        if (isArmstrong(num)) {
            System.out.println(num + " is an Armstrong number.");
        } else {
            System.out.println(num + " is NOT an Armstrong number.");
        }

        sc.close();
    }
}
