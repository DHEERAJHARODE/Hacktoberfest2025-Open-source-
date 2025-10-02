public class ReverseString {
    public static void main(String[] args) {
        String str = "Hello World";
        
        // Method 1: Using StringBuilder
        String reversed1 = new StringBuilder(str).reverse().toString();
        System.out.println("Reversed (StringBuilder): " + reversed1);

        // Method 2: Using loop
        String reversed2 = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reversed2 += str.charAt(i);
        }
        System.out.println("Reversed (Loop): " + reversed2);
    }
}
