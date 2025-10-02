public class LastOcc {
    static int lastoccer(int[] arr, int targ) {
        int st = 0;
        int end = arr.length - 1;
        int lo = -1;
        // if (arr[end] == targ)
        // return end;
        // while (st <= end) {
        // int mid = st + ((end - st) / 2);
        // if (arr[mid] == targ && arr[mid + 1] > targ)
        // return mid;
        // else if (arr[mid] > targ)
        // end = mid - 1;
        // else {
        // st = mid + 1;
        // }
        // }
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (arr[mid] == targ) {
                lo = mid;
                st = mid + 1;
            } else if (arr[mid] > targ)
                end = mid - 1;
            else
                st = mid + 1;
        }
        return lo;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 2, 5, 5, 5, 9, 23, 78, 345, 345, 896 };
        System.out.println(lastoccer(arr, 5));
    }
}
