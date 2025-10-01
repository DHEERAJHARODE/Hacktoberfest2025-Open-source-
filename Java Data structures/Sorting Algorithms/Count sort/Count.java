public class Count {
    static int[] PrintCount(int[] arr) {
        int max = Integer.MIN_VALUE;
        int n = arr.length;
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        int[] freqarr = new int[max + 1];
        for (i = 0; i < n; i++) {
            freqarr[arr[i]]++;
        }
        int k = 0;
        for (i = 0; i < freqarr.length; i++) {
            for (int j = 0; j < freqarr[i]; j++) {
                arr[k] = i;
                k++;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = { 6, 4, 7, 7, 4, 43, 3, 4, 2, 1, 5, 9, 0, 4, 0, 1 };
        int[] ans = PrintCount(arr);
        for (int i : ans)
            System.out.println(i);
    }
}