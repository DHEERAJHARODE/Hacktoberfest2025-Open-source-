public class TargElemIdx {
    static int findTarElemidx(int[] arr, int targ) {
        int st = 0;
        int end = arr.length - 1;
        int n = arr.length;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (arr[mid] == targ) {
                return mid;
            }
            if (arr[mid] < arr[n - 1]) {
                if (targ > arr[mid] && targ <= arr[n - 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (targ < arr[mid] && targ >= arr[0]) {
                    end = mid - 1;
                } else
                    st = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { 4, 5, 7, 8, 0, 1, 2, 3 };
        int targ = 3;
        System.out.println(findTarElemidx(arr, targ));
    }
}
