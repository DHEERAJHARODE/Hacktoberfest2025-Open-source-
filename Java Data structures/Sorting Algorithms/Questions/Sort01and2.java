public class Sort01and2 {// in this method we will sort in two pass means o(2n) or o(n+n);
    static void Sortplease(int[] arr) {
        int n = arr.length;
        int[] freqarr = new int[3];
        for (int i = 0; i < n; i++)
            freqarr[arr[i]]++;
        for (int i = 1; i <= 2; i++) {
            freqarr[i] += freqarr[i - 1];
        }
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            ans[freqarr[arr[i]] - 1] = arr[i];
            freqarr[arr[i]]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = ans[i];
    }

    public static void main(String[] args) {
        int[] arr = { 0, 2, 1, 2, 0, 0 };
        Sortplease(arr);
        for (int i : arr)
            System.out.print(i + " ");
    }
}
