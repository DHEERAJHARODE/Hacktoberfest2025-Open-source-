import java.util.ArrayList;
import java.util.List;

public class AddSpacesToString {

    public static String addSpaces(String s, int[] spaces) {
        StringBuilder result = new StringBuilder();
        int spaceIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            if (spaceIndex < spaces.length && i == spaces[spaceIndex]) {
                result.append(' ');
                spaceIndex++;
            }
            result.append(s.charAt(i));
        }

        return result.toString();
    }

    public static String addSpacesAtIntervals(String s, int interval) {
        if (interval <= 0) return s;

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && i % interval == 0) {
                result.append(' ');
            }
            result.append(s.charAt(i));
        }
        return result.toString();
    }

    public static String addSpacesBeforeUppercase(String s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && Character.isUpperCase(s.charAt(i))) {
                result.append(' ');
            }
            result.append(s.charAt(i));
        }
        return result.toString();
    }

    public static String addSpacesAroundSpecialChars(String s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!Character.isLetterOrDigit(c) && c != ' ') {
                if (i > 0 && result.charAt(result.length() - 1) != ' ') {
                    result.append(' ');
                }
                result.append(c);
                if (i < s.length() - 1) {
                    result.append(' ');
                }
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }

    public static String formatPhoneNumber(String phoneNumber) {
        String digits = phoneNumber.replaceAll("[^0-9]", "");
        if (digits.length() == 10) {
            return String.format("(%s) %s-%s",
                digits.substring(0, 3),
                digits.substring(3, 6),
                digits.substring(6));
        }
        return phoneNumber;
    }

    public static void main(String[] args) {
        System.out.println("Adding Spaces to Strings");
        System.out.println("========================");

        System.out.println("1. Adding spaces at specific indices:");
        String text1 = "LeetcodeHelpsMeLearn";
        int[] spaces1 = {8, 13, 15};
        String result1 = addSpaces(text1, spaces1);
        System.out.println("Original: \"" + text1 + "\"");
        System.out.println("With spaces at " + java.util.Arrays.toString(spaces1) + ": \"" + result1 + "\"");

        System.out.println("\n2. Adding spaces at regular intervals:");
        String text2 = "HelloWorldJavaProgramming";
        String result2 = addSpacesAtIntervals(text2, 5);
        System.out.println("Original: \"" + text2 + "\"");
        System.out.println("With spaces every 5 characters: \"" + result2 + "\"");

        System.out.println("\n3. Adding spaces before uppercase letters:");
        String text3 = "JavaProgrammingLanguage";
        String result3 = addSpacesBeforeUppercase(text3);
        System.out.println("Original: \"" + text3 + "\"");
        System.out.println("With spaces before uppercase: \"" + result3 + "\"");

        System.out.println("\n4. Adding spaces around special characters:");
        String text4 = "Hello,World!How@are#you?";
        String result4 = addSpacesAroundSpecialChars(text4);
        System.out.println("Original: \"" + text4 + "\"");
        System.out.println("With spaces around special chars: \"" + result4 + "\"");

        System.out.println("\n5. Formatting phone numbers:");
        String[] phoneNumbers = {"1234567890", "123-456-7890", "(123)4567890"};
        for (String phone : phoneNumbers) {
            String formatted = formatPhoneNumber(phone);
            System.out.println("Original: \"" + phone + "\" -> Formatted: \"" + formatted + "\"");
        }

        System.out.println("\n6. More test cases:");
        String[] testCases = {
            "spacing",
            "icodeinpython",
            "ThisIsATestString"
        };

        int[][] spaceIndices = {
            {0, 1, 3, 4, 6},
            {1, 5, 7, 13},
            {4, 6, 7, 11}
        };

        for (int i = 0; i < testCases.length; i++) {
            String original = testCases[i];
            String withSpaces = addSpaces(original, spaceIndices[i]);
            System.out.println("\"" + original + "\" -> \"" + withSpaces + "\"");
        }
    }
}