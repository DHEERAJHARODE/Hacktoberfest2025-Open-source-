public class Selection {// Selection sort..........this will take O(n^2) time complexity in every case,
                        // even in best case also .........that is why it is not recommended.........
    static int[] SortSelect(int[] arr) {
        int n = arr.length - 1;
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i; j <= n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = { 5, 4, 3, 2, 1, 0, 9 };
        int[] ans = SortSelect(arr);
        for (int i : ans)
            System.out.println(i);
    }
}