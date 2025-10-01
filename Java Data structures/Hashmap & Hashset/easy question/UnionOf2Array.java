import java.util.ArrayList;
import java.util.HashMap;

public class UnionOf2Array {
    public static void FindUnion(int[] arr1, int[] arr2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < arr1.length; i++) {
            if (!mp.containsKey(arr1[i])) {
                mp.put(arr1[i], 1);
            }
        }
        for (int i = 0; i < arr2.length; i++) {
            if (!mp.containsKey(arr2[i])) {
                mp.put(arr2[i], 1);
            }
        }
        System.out.println(mp.size());
    }

    public static void main(String[] args) {
        int[] arr1 = { 7, 3, 9 };
        int[] arr2 = { 6, 3, 9, 2, 9, 4 };
        FindUnion(arr1, arr2);
    }
}
