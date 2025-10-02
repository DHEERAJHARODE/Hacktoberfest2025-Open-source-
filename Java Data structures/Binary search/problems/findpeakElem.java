public class findpeakElem {
    public static int FindpeakEl(int[] nums) {
        int n = nums.length;
        int st = 0;
        // if (n == 1) //both codes are same...........in time complexity.....this one
        // is written by me..
        // return 0;
        // int end = n - 1;
        // int peakElem = -1;
        // while (st < end) {
        // int mid = st + ((end - st) / 2);
        // if (nums[mid + 1] > nums[mid]) {
        // peakElem = mid + 1;
        // st = mid + 1;
        // } else {
        // end = mid;
        // peakElem = mid;
        // }
        int end = n - 1;
        int peakElem = -1;
        while (st <= end) {
            int mid = st + ((end - st) / 2);
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1]))
                return mid;
            if (nums[mid + 1] > nums[mid])
                st = mid + 1;
            else
                end = mid - 1;
        }
        return peakElem;
    }

    public static void main(String[] args) {
        int[] arr = { 6, 5, 4, 3, 2, 3, 2 };
        System.out.println(FindpeakEl(arr));
    }
}