import java.util.Stack;

public class RemoveStarsFromString {

    public static String removeStars(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '*') {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                stack.push(c);
            }
        }

        StringBuilder result = new StringBuilder();
        for (char c : stack) {
            result.append(c);
        }

        return result.toString();
    }

    public static String removeStarsOptimized(String s) {
        StringBuilder result = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (c == '*') {
                if (result.length() > 0) {
                    result.deleteCharAt(result.length() - 1);
                }
            } else {
                result.append(c);
            }
        }

        return result.toString();
    }

    public static String removeAllStars(String s) {
        return s.replaceAll("\\*", "");
    }

    public static String removeStarsAndAdjacent(String s) {
        StringBuilder result = new StringBuilder();
        int i = 0;

        while (i < s.length()) {
            if (s.charAt(i) == '*') {
                if (result.length() > 0) {
                    result.deleteCharAt(result.length() - 1);
                }
                i++;
            } else {
                result.append(s.charAt(i));
                i++;
            }
        }

        return result.toString();
    }

    public static String removeStarsWithPattern(String s, String pattern) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (pattern.indexOf(c) != -1) {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                stack.push(c);
            }
        }

        StringBuilder result = new StringBuilder();
        for (char c : stack) {
            result.append(c);
        }

        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println("Removing Stars from Strings");
        System.out.println("============================");

        String[] testStrings = {
            "leet**cod*e",
            "erase*****",
            "ab*c*d*e",
            "a*b*c*",
            "***",
            "hello*world*",
            "programming*is*fun",
            "a**b**c"
        };

        System.out.println("1. Remove stars with backspace behavior:");
        for (String str : testStrings) {
            String result = removeStars(str);
            System.out.println("\"" + str + "\" -> \"" + result + "\"");
        }

        System.out.println("\n2. Optimized version:");
        for (String str : testStrings) {
            String result = removeStarsOptimized(str);
            System.out.println("\"" + str + "\" -> \"" + result + "\"");
        }

        System.out.println("\n3. Remove all stars (no backspace behavior):");
        String[] simpleTests = {"hello*world", "pro*gram*ming", "*start*end*"};
        for (String str : simpleTests) {
            String result = removeAllStars(str);
            System.out.println("\"" + str + "\" -> \"" + result + "\"");
        }

        System.out.println("\n4. Remove with custom pattern:");
        String testStr = "abc#def#ghi#";
        String result = removeStarsWithPattern(testStr, "#");
        System.out.println("Removing '#' with backspace: \"" + testStr + "\" -> \"" + result + "\"");

        System.out.println("\n5. Performance comparison test:");
        String longString = "a".repeat(1000) + "*".repeat(500) + "b".repeat(1000);

        long start = System.nanoTime();
        String stackResult = removeStars(longString);
        long stackTime = System.nanoTime() - start;

        start = System.nanoTime();
        String optimizedResult = removeStarsOptimized(longString);
        long optimizedTime = System.nanoTime() - start;

        System.out.println("Stack method time: " + stackTime + " ns");
        System.out.println("Optimized method time: " + optimizedTime + " ns");
        System.out.println("Results match: " + stackResult.equals(optimizedResult));
    }
}