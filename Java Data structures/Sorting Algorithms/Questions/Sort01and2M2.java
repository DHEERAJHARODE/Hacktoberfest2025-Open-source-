public class Sort01and2M2 {
    // this one is best method and this will take O(n) which is one pass
    // Solution.......................
    // important as interview perspection.............
    // In this problem we will sort in one pass.................
    static void Sortin1pass(int[] arr) {
        int low = 0;
        int mid = 0;
        int n = arr.length;
        int hi = n - 1;
        while (hi >= mid) {
            if (arr[mid] == 0) {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                mid++;
                low++;
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                int temp = arr[mid];
                arr[mid] = arr[hi];
                arr[hi] = temp;
                hi--;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 2, 0, 1 };
        Sortin1pass(arr);
        for (int i : arr)
            System.out.print(i + " ");
    }
}
