public class ArmstrongNumber {

    // Helper method to calculate the power recursively
    public static int power(int base, int exp) {
        if (exp == 0) {
            return 1;
        }
        return base * power(base, exp - 1);
    }

    // Recursive method to calculate sum of digits raised to power of count
    public static int armstrongSum(int num, int count) {
        if (num == 0) {
            return 0;
        }
        int digit = num % 10;
        return power(digit, count) + armstrongSum(num / 10, count);
    }

    // Method to check if a number is Armstrong
    public static boolean isArmstrong(int num) {
        int count = String.valueOf(num).length(); // count of digits
        return num == armstrongSum(num, count);
    }

    public static void main(String[] args) {
        int number = 153; // Test number
        if (isArmstrong(number)) {
            System.out.println(number + " is an Armstrong number.");
        } else {
            System.out.println(number + " is not an Armstrong number.");
        }
    }
}
