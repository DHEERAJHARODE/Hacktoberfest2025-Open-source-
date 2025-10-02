public class Redix {
    static int findMax(int[] arr) {
        int max = Integer.MIN_VALUE;
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    static int[] PrintCountSort(int[] arr, int place) {
        int[] freq = new int[10];
        int n = arr.length;
        int m = freq.length;
        int i;
        for (i = 0; i < n; i++) {// to get freqqarr
            int x = (arr[i] / place) % 10;
            freq[x]++;
        }
        for (i = 1; i < m; i++)// to get prefix sum freqarr.............
            freq[i] += freq[i - 1];
        int[] ans = new int[n];
        for (i = n - 1; i >= 0; i--) {// to put elements..........................
            int x = (arr[i] / place) % 10;
            ans[freq[x] - 1] = arr[i];
            freq[x]--;
        }
        for (i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
        return arr;
    }

    static int[] RedixSort(int[] arr) {
        int n = arr.length;
        int max = findMax(arr);
        int place = 1;
        for (int i = max; i / place != 0; place *= 10) {
            arr = PrintCountSort(arr, place);
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = { 823, 2, 89, 76, 0, 1087, 9, 456 };
        int[] ans = RedixSort(arr);
        for (int i : ans)
            System.out.println(i);
    }
}