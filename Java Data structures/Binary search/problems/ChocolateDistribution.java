public class ChocolateDistribution {
    static int FindChocDist(int[] arr, int Students) {
        int st = 1;
        int end = (int) 1e9;
        int ans = -1;
        if (Students > arr.length)
            return ans;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (IsDistributable(arr, mid, Students)) {// boolean.....
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    static boolean IsDistributable(int[] arr, int mid, int Students) {
        int NoOfStudent = 1;
        int Choco = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > mid)
                return false;
            if (Choco + arr[i] <= mid) {
                Choco += arr[i];
            } else {
                NoOfStudent++;
                Choco = 0;
                Choco += arr[i];
            }
        }
        if (NoOfStudent > Students)
            return false;
        return true;
    }

    public static void main(String[] args) {
        int[] arr = { 5, 3, 1, 4, 2 };
        int Students = 3;
        int ans = FindChocDist(arr, Students);
        System.out.println(ans);
    }
}
