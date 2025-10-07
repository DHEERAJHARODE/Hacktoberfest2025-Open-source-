public class StringCompression {

    public static String compressString(String str) {
        if (str == null || str.length() <= 1) {
            return str;
        }

        StringBuilder compressed = new StringBuilder();
        int count = 1;
        char currentChar = str.charAt(0);

        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == currentChar) {
                count++;
            } else {
                compressed.append(currentChar).append(count);
                currentChar = str.charAt(i);
                count = 1;
            }
        }

        compressed.append(currentChar).append(count);

        return compressed.length() < str.length() ? compressed.toString() : str;
    }

    public static void main(String[] args) {
        String[] testStrings = {
            "aabcccccaaa",
            "abcdef",
            "aabbcc",
            "aaabbbccc",
            "a",
            ""
        };

        System.out.println("String Compression Algorithm");
        System.out.println("============================");

        for (String str : testStrings) {
            String compressed = compressString(str);
            System.out.println("Original: \"" + str + "\" -> Compressed: \"" + compressed + "\"");
        }
    }
}