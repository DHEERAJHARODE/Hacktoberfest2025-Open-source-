import java.util.ArrayList;
import java.util.List;

public class PalindromicStrings {

    public static boolean isPalindrome(String str) {
        if (str == null) return false;

        str = str.toLowerCase().replaceAll("[^a-zA-Z0-9]", "");
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

    public static List<String> findAllPalindromes(String str) {
        List<String> palindromes = new ArrayList<>();

        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j <= str.length(); j++) {
                String substring = str.substring(i, j);
                if (substring.length() > 1 && isPalindrome(substring)) {
                    palindromes.add(substring);
                }
            }
        }
        return palindromes;
    }

    public static String longestPalindrome(String str) {
        if (str == null || str.length() == 0) return "";

        String longest = "";

        for (int i = 0; i < str.length(); i++) {
            String oddPalindrome = expandAroundCenter(str, i, i);
            String evenPalindrome = expandAroundCenter(str, i, i + 1);

            String currentLongest = oddPalindrome.length() > evenPalindrome.length() ?
                                  oddPalindrome : evenPalindrome;

            if (currentLongest.length() > longest.length()) {
                longest = currentLongest;
            }
        }

        return longest;
    }

    private static String expandAroundCenter(String str, int left, int right) {
        while (left >= 0 && right < str.length() && str.charAt(left) == str.charAt(right)) {
            left--;
            right++;
        }
        return str.substring(left + 1, right);
    }

    public static void main(String[] args) {
        System.out.println("Palindromic Strings Checker");
        System.out.println("===========================");

        String[] testStrings = {
            "racecar",
            "A man a plan a canal Panama",
            "race a car",
            "hello",
            "madam",
            "abccba",
            "babad",
            "cbbd"
        };

        for (String str : testStrings) {
            System.out.println("\nString: \"" + str + "\"");
            System.out.println("Is palindrome: " + isPalindrome(str));

            if (str.length() <= 20) {
                List<String> palindromes = findAllPalindromes(str);
                System.out.println("All palindromic substrings: " + palindromes);
            }

            String longest = longestPalindrome(str);
            System.out.println("Longest palindromic substring: \"" + longest + "\"");
        }

        System.out.println("\n" + "=".repeat(40));
        System.out.println("Additional palindrome checks:");

        String[] additionalTests = {"noon", "level", "rotator", "civic", "radar"};
        for (String test : additionalTests) {
            System.out.println(test + " -> " + (isPalindrome(test) ? "Palindrome" : "Not a palindrome"));
        }
    }
}