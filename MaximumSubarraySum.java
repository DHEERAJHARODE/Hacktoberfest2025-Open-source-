/**
 * Algorithm Name: Maximum Subarray Sum
 * Category: Dynamic Programming
 * Difficulty: Medium
 *
 * Approach:
 * Use Kadane's Algorithm:
 * - Initialize two variables:
 *   1) maxCurrent: maximum sum ending at current position
 *   2) maxGlobal: maximum sum found so far
 * - Traverse the array:
 *     maxCurrent = max(arr[i], maxCurrent + arr[i])
 *     maxGlobal = max(maxGlobal, maxCurrent)
 * - maxGlobal contains the maximum subarray sum at the end.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

public class MaximumSubarraySum {

    // Function to find maximum subarray sum
    public static int maxSubArray(int[] nums) {
        int maxCurrent = nums[0]; // Maximum sum ending at current index
        int maxGlobal = nums[0];  // Maximum sum found so far

        for (int i = 1; i < nums.length; i++) {
            // Either extend the current subarray or start a new subarray
            maxCurrent = Math.max(nums[i], maxCurrent + nums[i]);
            // Update global maximum
            maxGlobal = Math.max(maxGlobal, maxCurrent);
        }

        return maxGlobal;
    }

    // Driver code to test the function
    public static void main(String[] args) {
        int[] nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int[] nums2 = {1, 2, 3, 4, 5};
        int[] nums3 = {-1, -2, -3, -4};

        System.out.println("Maximum Subarray Sum of nums1: " + maxSubArray(nums1)); // Output: 6
        System.out.println("Maximum Subarray Sum of nums2: " + maxSubArray(nums2)); // Output: 15
        System.out.println("Maximum Subarray Sum of nums3: " + maxSubArray(nums3)); // Output: -1
    }
}
