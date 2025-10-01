public class Count1 {// time complexity in worst case ===== O(n+m) , in avg case O(n+m) , and in
                     // worst case O(n) ->(when m is 1)
    static int findMax(int[] arr) {
        int max = Integer.MIN_VALUE;
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    static void PrintCountSort(int[] arr) {
        int max = findMax(arr);
        int[] freq = new int[max + 1];
        int n = arr.length;
        int m = freq.length;
        int i;
        for (i = 0; i < n; i++)
            freq[arr[i]]++;
        for (i = 1; i < m; i++)// to get prefix sum freqarr.............
            freq[i] += freq[i - 1];
        int[] ans = new int[n];
        for (i = n - 1; i >= 0; i--) {// to put elements..........................
            ans[freq[arr[i]] - 1] = arr[i];
            freq[arr[i]]--;
        }
        for (i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
    }

    public static void main(String[] args) {
        int[] arr = { 5, 1, 3, 1, 2, 4, 1 };
        PrintCountSort(arr);
        for (int i : arr)
            System.out.println(i);
    }
}
