import java.util.*;

public class GroupAnagram {
    public static List<List<String>> groupAnagrams(String[] strs) {
        // Create a HashMap to map a sorted string to a list of its anagrams
        HashMap<String, List<String>> mp = new HashMap<>();

        // Iterate over each string in the input array
        for (String str : strs) {
            // Convert the string to a character array
            char[] chararr = str.toCharArray();

            // Sort the character array to get the canonical form of the anagram
            Arrays.sort(chararr);

            // Convert the sorted character array back to a string
            String SortedStr = new String(chararr);

            // If the sorted string is not already in the map, add it with a new list
            if (!mp.containsKey(SortedStr)) {
                mp.put(SortedStr, new ArrayList<>());
            }

            // Add the original string to the list corresponding to the sorted string
            mp.get(SortedStr).add(str);
        }

        // Prepare the final list to hold all the grouped anagrams
        List<List<String>> list = new ArrayList<>();

        // Add each group of anagrams from the map to the final list
        for (var k : mp.values()) {
            list.add(k);
        }

        // Return the list of anagram groups
        return list;
    }

    public static void main(String[] args) {
        String[] strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
        List<List<String>> ans = groupAnagrams(strs);
        System.out.println(ans);
    }
}
