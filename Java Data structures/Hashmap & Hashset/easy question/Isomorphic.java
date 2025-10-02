import java.util.HashMap;

public class Isomorphic {// means the pattern of first string character and second string character must
                         // be same , and unique character should also have an unique value...........
    public static boolean Isisomorphic(String one, String two) {
        HashMap<Character, Character> mp = new HashMap<>();
        if (one.length() != two.length())
            return false;
        for (int i = 0; i < one.length(); i++) {
            if (mp.containsKey(one.charAt(i))) {
                if (mp.get(one.charAt(i)) != two.charAt(i))
                    return false;
            } else {
                if (mp.containsValue(two.charAt(i)))
                    return false;
                mp.put(one.charAt(i), two.charAt(i));
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String one = "aabac";
        String two = "xxyxw";// false for xxyxx
        System.out.println(Isisomorphic(one, two));
    }
}
