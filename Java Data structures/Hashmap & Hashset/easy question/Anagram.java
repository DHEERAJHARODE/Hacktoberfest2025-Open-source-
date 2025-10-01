import java.util.*;

public class Anagram {
    public static boolean IsAnagram(String one, String two) {// Most efficient method........
        // method 1 not that much efficient...........
        HashMap<Character, Integer> mp = new HashMap<>();
        if (one.length() != two.length())// check if string1 length is equals to string2 length.........
            return false;
        for (int i = 0; i < one.length(); i++) {// to insert element of first string in the map...........
            if (mp.containsKey(one.charAt(i)))
                mp.put(one.charAt(i), mp.get(one.charAt(i)) + 1);
            else
                mp.put(one.charAt(i), 1);
        }
        for (int i = 0; i < one.length(); i++) {// to check if the same character and no. of character(frequency) from
                                                // second
                                                // string is present in the map or not
            if (!mp.containsKey(two.charAt(i))) {
                return false;
            } else {
                mp.put(two.charAt(i), mp.get(two.charAt(i)) - 1);
            }
        }
        for (var v : mp.values()) {// to check whether each value in the map is zero on not , if zero that means
                                   // both strings are anagram......
            if (v != 0)
                return false;
        }
        return true;
    }

    static boolean AnagramH(String one, String two) {// less efficient cause it contains more space...........
        HashMap<Character, Integer> mp = new HashMap<>();
        HashMap<Character, Integer> mpp = new HashMap<>();
        if (one.length() != two.length())
            return false;
        for (int i = 0; i < one.length(); i++) {
            if (mp.containsKey(one.charAt(i)))
                mp.put(one.charAt(i), mp.get(one.charAt(i)) + 1);
            else
                mp.put(one.charAt(i), 1);
        }
        for (int i = 0; i < two.length(); i++) {
            if (mpp.containsKey(two.charAt(i)))
                mpp.put(two.charAt(i), mpp.get(two.charAt(i)) + 1);
            else
                mpp.put(two.charAt(i), 1);
        }
        return mp.equals(mpp);
    }

    public static void main(String[] args) {
        String one = "vasnh";
        String two = "shvan";
        System.out.println(AnagramH(one, two));
    }
}
