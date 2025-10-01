public class SearchAndSquarRoot {
    public static int FindSqrtBinarysearch(int targ) {
        int st = 0;
        int end = targ;
        int ans = -1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (mid * mid == targ) {
                return mid;
            } else if (targ > mid * mid) {
                ans = mid;
                st = mid + 1;
            } else
                end = mid - 1;
        }
        return ans;

    }

    public static void main(String[] args) {
        System.out.println(FindSqrtBinarysearch(149));
    }
}
