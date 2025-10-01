public class Peakidx {
    static int FindPeakIdx(int[] arr) {
        int n = arr.length;
        int st = 0;
        int end = n - 1;
        int peakidx = -1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (arr[mid + 1] > arr[mid] && arr[mid + 1] <= end) {
                peakidx = mid + 1;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return peakidx;
    }

    public static void main(String[] args) {
        int[] arr = { 0, 1, 3, 4, 2, 1 };
        System.out.println(FindPeakIdx(arr));
    }
}
