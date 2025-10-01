public class BestSort {// Bubble sort...........................best case O(n) of bubble sort, if
                       // elements
                       // are somehow sorted...........
                       // But if elements are not sorted so it will also take O(n*n) time complexity
                       // which is worst case..............
    public static int[] BestSortarr(int[] arr) {
        int n = arr.length;
        boolean flag = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = true;// Because swaping is happening........
                }
            }
            if (!flag) {// if there wasn't any swap in the last iteration.....
                return arr;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 3, 2, 4, 5 };
        int[] ans = BestSortarr(arr);
        for (int i : ans) {
            System.out.println(i);
        }
    }
}