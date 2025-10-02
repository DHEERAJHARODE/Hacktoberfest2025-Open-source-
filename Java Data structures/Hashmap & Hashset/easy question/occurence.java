import java.util.HashMap;

public class occurence {
    public static void Findoccurence(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (mp.containsKey(arr[i])) {
                mp.put(arr[i], mp.get(arr[i]) + 1);
            } else {
                mp.put(arr[i], 1);
            }
        }
        for (var k : mp.keySet()) {
            if (mp.get(k) > (arr.length / 3)) {
                System.out.print(k + " ");
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2 };
        Findoccurence(arr);
    }
}
