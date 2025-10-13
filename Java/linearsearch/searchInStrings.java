package Java.linearsearch;
public class searchInStrings {
    public static void main(String[] args) {
        String name = "Ruturaj";
        char target = 'u';
        Search(name, target);
        Search2(name, target);
    }

    // Method 1: Search using charAt()
    static void Search(String str, char target) {
        boolean flag = false; // assume not found

        if (str.length() == 0) { // check empty string
            System.out.println("String is empty.");
            return;
        }

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == target) { // compare each character
                flag = true;
                break; // stop when found
            }
        }

        // display result
        if (flag)
            System.out.println("Target '" + target + "' found in string \"" + str + "\".");
        else
            System.out.println("Target '" + target + "' not found in string \"" + str + "\".");
    }

    // Method 2: Search using toCharArray()
    static void Search2(String str, char target) {
        boolean flag = false; // assume not found

        if (str.length() == 0) {
            System.out.println("String is empty.");
            return;
        }

        for (char ch : str.toCharArray()) { // iterate through char array
            if (ch == target) {
                flag = true;
                break;
            }
        }

        // display result
        if (flag)
            System.out.println("Target '" + target + "' found in string \"" + str + "\".");
        else
            System.out.println("Target '" + target + "' not found in string \"" + str + "\".");
    }
}
