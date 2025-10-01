public class SearchInDuplicateElem {
    static int SearchVro(int[] arr, int targ) {
        int n = arr.length;
        int st = 0;
        int end = n - 1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if (arr[mid] == targ)
                return mid;
            else if (arr[mid] == arr[st] && arr[mid] == arr[end]) {
                st++;
                end--;
            } else if (arr[mid] <= arr[end]) {
                if (targ > arr[mid] && targ <= arr[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (targ < arr[mid] && targ >= arr[st]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 5, 6, 0, 0, 1, 2 };
        int targ = 3;
        System.out.println(SearchVro(arr, targ));
    }
}
