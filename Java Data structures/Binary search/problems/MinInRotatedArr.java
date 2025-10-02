public class MinInRotatedArr {
    static int findMinidx(int[] arr) {
        int st = 0;
        int end = arr.length - 1;
        int n = arr.length;
        int minidx = -1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (arr[mid] > arr[n - 1]) {
                st = mid + 1;
            } else {
                minidx = mid;
                end = mid - 1;
            }
        }
        return minidx;
    }

    public static void main(String[] args) {
        int[] arr = { 4, 5, 6, 7, 0, 1, 2 };
        System.out.println(findMinidx(arr));
    }
}
