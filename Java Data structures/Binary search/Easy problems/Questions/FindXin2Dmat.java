public class FindXin2Dmat {
    public static boolean findXin2d(int[][] arr, int targ) {
        int st = 0;
        int i = 0;
        int n = arr.length;
        int m = arr[i].length;
        int end = n * m - 1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            // we can also do it....but there is also a way..........
            // int mr = mid / m;
            // int mc = mid % m;
            int midElem = arr[mid / m][mid % m];
            if (midElem == targ) {
                return true;
            } else if (midElem > targ) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] arr = { { 1, 2, 3, 5 }, { 6, 8, 9, 13 }, { 21, 34, 65, 123 } };
        int targ = 8;
        System.out.println(findXin2d(arr, targ));
    }
}
