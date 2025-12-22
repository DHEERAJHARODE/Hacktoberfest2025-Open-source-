import java.util.*;

public class checkVowel {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("enter the word");
        char ch = s.next().charAt(0);
        switch (Character.toLowerCase(ch)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                System.out.println("the given letter is vowel ");
                break;
            default:
                System.out.println("the given letter is not an vowel");
        }
        s.close();
    }
}
