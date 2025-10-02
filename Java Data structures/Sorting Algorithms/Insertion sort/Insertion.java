public class Insertion {// insertion sort.......................best case O(n) and avg & worst case time
                        // comp. is O(n)
    // Space complexity is O(1)................................
    public static int[] SortInsertion(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n - 1; i++) {
            int j = i;
            while (j > 0 && arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = { 5, 4, 3, 2, 1, 0, 9 };
        int[] ans = SortInsertion(arr);
        for (int i : ans) {
            System.out.println(i);
        }
    }
}