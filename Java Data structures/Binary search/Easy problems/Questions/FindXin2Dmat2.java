public class FindXin2Dmat2 {
    public static boolean findx(int[][] arr, int targ) {
        // int st = 0;
        // int i = 0;
        // int n = arr.length;
        // int m = arr[i].length;
        // int end = m - 1;
        // while (i < n) {
        // int mid = st + ((end - st) / 2);
        // int midElem = arr[i][mid];
        // if (midElem == targ) {
        // return true;
        // } else if (midElem > targ) {
        // end = mid - 1;
        // } else {
        // st = mid + 1;
        // }
        // if (st > end) {
        // end = m - 1;
        // st = 0;
        // i++;
        // }
        // }
        int i = 0;// in worst case time complexity will be o(n+m).................
        int n = arr.length;
        int m = arr[i].length;
        int j = m - 1;
        while (i < n && j >= 0) {
            int currElem = arr[i][j];
            if (currElem == targ)
                return true;
            else if (currElem < targ)
                i++;
            else
                j--;
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] arr = { { 1, 3, 5, 7 }, { 2, 6, 9, 13 }, { 4, 8, 14, 26 }, { 10, 24, 56, 78 } };
        int targ = 10;
        System.out.println(findx(arr, targ));
    }
}
