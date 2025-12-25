import java.util.Scanner;

public class MedianOfSortedArrays {

    // Method to find the median of two sorted arrays
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // Ensure that nums1 is the smaller array to perform binary search on it
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length;
        int n = nums2.length;
        int low = 0, high = m;

        // Perform binary search on the smaller array
        while (low <= high) {
            int partition1 = (low + high) / 2; // Midpoint for nums1
            int partition2 = (m + n + 1) / 2 - partition1; // Midpoint for nums2

            // Handle edge cases where partition1 or partition2 is at array boundary
            int maxLeft1 = (partition1 == 0) ? Integer.MIN_VALUE : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? Integer.MAX_VALUE : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? Integer.MIN_VALUE : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? Integer.MAX_VALUE : nums2[partition2];

            // Check if correct partition is found
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is even, return the average of the middle two elements
                if ((m + n) % 2 == 0) {
                    return (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2.0;
                } else {
                    // If odd, return the middle element
                    return Math.max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Move the partition to the left in nums1
                high = partition1 - 1;
            } else {
                // Move the partition to the right in nums1
                low = partition1 + 1;
            }
        }

        // This line will never be reached if input arrays are sorted as per the problem constraint
        throw new IllegalArgumentException("Input arrays are not sorted.");
    }

    // Main method to take input from the user and find the median
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the size and elements of the first sorted array
        System.out.print("Enter size of first array: ");
        int m = scanner.nextInt();
        int[] nums1 = new int[m];
        System.out.println("Enter elements of the first sorted array:");
        for (int i = 0; i < m; i++) {
            nums1[i] = scanner.nextInt();
        }

        // Input the size and elements of the second sorted array
        System.out.print("Enter size of second array: ");
        int n = scanner.nextInt();
        int[] nums2 = new int[n];
        System.out.println("Enter elements of the second sorted array:");
        for (int i = 0; i < n; i++) {
            nums2[i] = scanner.nextInt();
        }

        // Create an instance of the class and call the method to find the median
        MedianOfSortedArrays solution = new MedianOfSortedArrays();
        double median = solution.findMedianSortedArrays(nums1, nums2);

        // Output the median
        System.out.println("Median: " + median);

        // Close the scanner
        scanner.close();
    }
}
