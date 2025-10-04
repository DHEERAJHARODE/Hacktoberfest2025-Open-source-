/**
 * BinarySearch
 */
public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {3, 4, 5, 6, 7, 8, 9, 10};
        int start = 0;
        int end = arr.length - 1;
        int target = 8;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                System.out.println(mid);
                break;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
}