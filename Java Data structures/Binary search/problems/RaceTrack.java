public class RaceTrack {
    static int FindLargestMinDis(int[] arr, int kids) {
        int st = 1;
        int end = (int) 1e9;
        int ans = -1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (IsDistanceMinimizable(arr, mid, kids)) {
                ans = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    static boolean IsDistanceMinimizable(int[] arr, int mid, int kids) {
        int kidsplaced = 1;
        int k1 = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - arr[k1] >= mid) {
                kidsplaced++;
                k1 = i;
            }
        }
        if (kidsplaced < kids) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 4, 8, 9 };
        int kids = 3;
        System.out.println(FindLargestMinDis(arr, kids));
    }
}
