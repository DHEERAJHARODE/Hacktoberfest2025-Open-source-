public class SwapInLiTime {
    static int[] SortInLinTime(int[] arr) {
        int x = -1;
        int y = -1;
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                if (x == (-1)) {// if distortion is first time.......
                    x = i - 1;
                    y = i;
                } else {// if distortion is second time......
                    y = i;
                }
            }
        }
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = { 3, 8, 6, 7, 5, 9, 10 };
        int[] ans = SortInLinTime(arr);
        for (int i : arr)
            System.out.print(i + " ");
    }
}