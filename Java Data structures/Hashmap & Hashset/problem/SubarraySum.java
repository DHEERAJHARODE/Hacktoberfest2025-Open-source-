import java.util.HashMap;

public class SubarraySum {
    public static int findSubarraySum(int[] arr, int target) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int count = 0;
        int prefixsum = 0;
        mp.put(0, 1);// exception case........for starting single element if that is equals to
        // target......
        for (int i = 0; i < arr.length; i++) {
            prefixsum += arr[i];
            if (mp.containsKey(prefixsum - target)) {
                count += mp.get(prefixsum - target);
            }
            if (mp.containsKey(prefixsum)) {
                mp.put(prefixsum, mp.get(prefixsum) + 1);
            } else {
                mp.put(prefixsum, 1);
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = { 10, 2, -2, -20, 10 };
        int ans = findSubarraySum(arr, -10);
        System.out.println(ans);
    }
}
