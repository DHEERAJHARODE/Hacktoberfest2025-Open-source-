import java.util.*;

public class LargestSumSubarray {
    public static int FindLargSubarray(int[] arr) {
        int n = arr.length;
        int max = 0;
        int prefixsum = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(prefixsum, -1);
        for (int i = 0; i < n; i++) {
            prefixsum += arr[i];
            if (mp.containsKey(prefixsum)) {// if map contains the prefix sum ever before..........
                int SubArrayLength = i - mp.get(prefixsum);// length of the current subarray...............
                max = Math.max(max, SubArrayLength);// Store the maximum length out of them.....
            } else {
                mp.put(prefixsum, i);// Insert the element..........
            }
        }
        return max;// return the maximum subbarray length..........
    }

    public static void main(String[] args) {
        int[] arr = { 15, -2, 2, -8, 1, 7, 10 };
        System.out.println(FindLargSubarray(arr));
    }
}