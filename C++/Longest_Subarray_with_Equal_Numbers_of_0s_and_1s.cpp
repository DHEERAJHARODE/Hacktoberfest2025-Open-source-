// Problem Statement
// Given a binary array (containing only 0s and 1s), 
// find the length of the longest contiguous subarray with an equal number of 0s and 1s.


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> sumIndexMap;
    int maxLength = 0;
    int sum = 0;
    
    // Initialize the sumIndexMap with sum 0 at index -1
    sumIndexMap[0] = -1;
    
    for (int i = 0; i < nums.size(); ++i) {
        // Convert 0s to -1s
        sum += (nums[i] == 0) ? -1 : 1;
        
        if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLength = max(maxLength, i - sumIndexMap[sum]);
        } else {
            sumIndexMap[sum] = i;
        }
    }
    
    return maxLength;
}

int main() {
    vector<int> arr = {0, 1, 0, 0, 1, 1, 0};
    cout << "Length of the longest subarray with equal number of 0s and 1s: " << findMaxLength(arr) << endl;
    return 0;
}


// Explanation
// Initialization:

// Use an unordered map sumIndexMap to store the first occurrence of each cumulative sum.
// Initialize the sum to 0 and set sumIndexMap[0] = -1 to handle the edge case where the 
// subarray starts from index 0.
// Iterate through the array:

// Convert 0s to -1s and 1s remain as they are.
// Calculate the running sum as you iterate through the array.
// If the running sum has been seen before, it means there is a subarray with an equal number 
// of 0s and 1s between the previous occurrence of this sum and the current index.
// Update the maximum length if the current subarray is longer than the previously found subarrays.
// If the running sum is not in the map, store the current index as its first occurrence.
// Output the result:

// The length of the longest subarray with an equal number of 0s and 1s is printed.
// This solution has a time complexity of O(n) and space complexity of O(n), making it efficient for 
// large input sizes.