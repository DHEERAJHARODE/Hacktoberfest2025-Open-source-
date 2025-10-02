import java.util.HashMap;

public class MostFrequentElement {
    public static int Findfreq(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (var elem : arr) {
            if (!mp.containsKey(elem)) {
                mp.put(elem, 1);
            } else {
                mp.put(elem, mp.get(elem) + 1);
            }
        }
        int key = 0;
        int val = 0;
        for (var e : mp.entrySet()) {
            if (e.getValue() > val) {
                val = e.getValue();
                key = e.getKey();
            }
        }
        return key;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 5, 1, 2, 6, 1, 4, 2, 8, 1, 6 };
        int ans = Findfreq(arr);
        System.out.println(ans + " is the most frequent element in the array");
    }
}