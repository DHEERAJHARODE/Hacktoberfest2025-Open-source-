public class RecBinary {
    public static boolean recurbinary(int[] arr, int st, int end, int targ) {
        if (st > end)// Base Case......
            return false;
        int mid = st + ((end - st) / 2);// (st + end) / 2, this formula can cause overflow conditions for big integer
                                        // values thats why we used that formula instead of this
                                        // formula....................indirectly that formula's result is also
                                        // (st-end)/2.....but it saves us form overflow conditions...........
        if (arr[mid] == targ)// if element found so return true.........
            return true;
        else if (arr[mid] > targ) {
            end = mid - 1;
            return recurbinary(arr, st, end, targ);// Subproblems
        } else {
            st = mid + 1;
            return recurbinary(arr, st, end, targ);// Subproblems
        }
    }

    public static void main(String[] args) {
        int[] arr = { 1, 3, 8, 9, 23, 46, 73, 89 };
        int st = 0;
        int end = arr.length - 1;
        int targ = 73;
        System.out.println(recurbinary(arr, st, end, targ));
    }
}
