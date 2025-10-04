class Solution {
    int maxSubarraySum(int arr[]) {
        int maxSum = arr[0];
        int currSum = arr[0];

        for (int i = 1; i < arr.length; i++) {
            // Ya to current element se naya subarray start karo,
            // ya phir purane subarray me add karo
            currSum = Math.max(arr[i], currSum + arr[i]);

            // max sum ko update karte raho
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
    }
}
