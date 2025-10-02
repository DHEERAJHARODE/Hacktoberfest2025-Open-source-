import java.util.HashSet;

public class HappyNumber {// if the number's digit's square sum ends in 1.......then it is happy number
                          // otherwise no......

    public static boolean isHappy(int n) {
        // Set to store the sums we've seen before to detect cycles
        HashSet<Integer> seenSums = new HashSet<>();
        int sum = 0;
        int currentNumber = n;

        // Loop until we either find a happy number (sum == 1) or a cycle (repeated sum)
        while (sum != 1) {
            sum = 0;

            // Calculate the sum of the squares of the digits
            while (currentNumber > 0) {
                int digit = currentNumber % 10;
                sum += digit * digit;
                currentNumber /= 10;
            }

            // Check if we've seen this sum before (cycle detection)
            if (seenSums.contains(sum)) {
                return false; // Not a happy number
            }

            // Add the current sum to the set of seen sums
            seenSums.add(sum);

            // If sum equals 1, it's a happy number
            if (sum == 1) {
                break;
            } else {
                // Otherwise, continue with the new sum as the current number
                currentNumber = sum;
            }
        }

        // If we exit the loop with sum == 1, the number is happy
        return true;
    }

    public static void main(String[] args) {
        int n = 19;
        System.out.println(isHappy(n));
    }
}
