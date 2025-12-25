//basic driver code for test cases
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int[] nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Max subarray sum for nums1: " + solution.maxSubArray(nums1)); // Expected output: 6

        // Test case 2
        int[] nums2 = {1};
        System.out.println("Max subarray sum for nums2: " + solution.maxSubArray(nums2)); // Expected output: 1

        // Test case 3
        int[] nums3 = {5, 4, -1, 7, 8};
        System.out.println("Max subarray sum for nums3: " + solution.maxSubArray(nums3)); // Expected output: 23

        // Test case 4
        int[] nums4 = {-1, -2, -3, -4};
        System.out.println("Max subarray sum for nums4: " + solution.maxSubArray(nums4)); // Expected output: -1
    }
}

// main code using Kedan's Algorithm
class Solution {
    public int maxSubArray(int[] nums) {
        int sum=0;
        int ans=nums[0];
        
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            ans=Math.max(ans,sum);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
}
