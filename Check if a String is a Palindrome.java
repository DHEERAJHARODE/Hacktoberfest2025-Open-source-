/* 
💻 Question: Check if a String is a Palindrome
🔸 Problem Statement:

Given a string, determine whether it is a palindrome — a word or sentence that reads the same forwards and backwards.
Ignore case differences and non-alphanumeric characters (like spaces, punctuation, etc.).

🔹 Input:

A single string s (may contain letters, digits, spaces, or symbols)

🔹 Output:

Return true if the string is a palindrome, false otherwise.

🔹 Constraints:

1 <= s.length <= 10^5

The string may contain uppercase/lowercase letters, digits, spaces, and punctuation.

Must run in O(n) time complexity.

📥 Example Input:
Input: "A man, a plan, a canal: Panama"

📤 Example Output:
Output: true

📥 Example Input 2:
Input: "race a car"

📤 Example Output 2:
Output: false
*/
/*
APPROCH::
1.Clean the String:

Remove all non-alphanumeric characters using regex.

Convert the entire string to lowercase to ensure case-insensitive comparison.

2.Two-Pointer Technique:

Use two pointers:

left starts from the beginning of the string.

right starts from the end.

3.Compare characters at both pointers.

If they don't match → it's not a palindrome → return false.

If they match → move left++ and right-- and continue checking.

Return true:

If all characters match till the middle, return true — it's a palindrome.*/

public class PalindromeChecker {

    public static boolean isPalindrome(String str) {
        if (str == null) return false;

        // Remove non-alphanumeric characters and convert to lowercase
        str = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();

        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {
        String input = "A man, a plan, a canal: Panama";
        System.out.println("Is palindrome? " + isPalindrome(input));
    }
}
