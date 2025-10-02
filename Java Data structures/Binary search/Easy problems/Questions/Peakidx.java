public class Peakidx {
    static int FindPeakIdx(int[] arr) {
        int n = arr.length;
        int st = 0;
        int end = n - 1;
        int peakidx = -1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (arr[mid + 1] > arr[mid]) {// if my next element is greater than curr then next could be peak......
                peakidx = mid + 1;
                st = mid + 1;// and then serch in next half
            } else {// else curr could be peak........
                peakidx = mid;
                end = mid - 1;// and then serch in prev half......
            }
        }
        return peakidx;
    }

    public static void main(String[] args) {
        int[] arr = { 0, 1, 3, 4, 2, 1 };
        System.out.println("Peak index is : " + FindPeakIdx(arr));
    }
}
