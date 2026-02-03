public class Palindrome {
    public static boolean isPalindrome(int n) {
        if (n < 0) {
            return false; // Negative numbers are not palindromes
        }

        int original = n;
        int reversed = 0;

        while (n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }

        return original == reversed;
    }

    public static void main(String[] args) {
        int N = 124321;
        boolean res = isPalindrome(N);
        System.out.println(res);
    }
}
