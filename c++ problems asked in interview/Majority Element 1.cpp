// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// Example 1:

// Input Format: N = 3, nums[] = {3,2,3}

// Result: 3

// Example 2:

// Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}

// Result: 2



// Approach: 

// Initialize 2 variables: 
// Count –  for tracking the count of element
// Element – for which element we are counting
// Traverse through nums array.
// If Count is 0 then initialize the current traversing integer of array as Element 
// If the traversing integer of array and Element are same increase Count by 1
// If they are different decrease Count by 1
// The integer present in Element is the result we are expecting 


// Code

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
    }
};

Time Complexity : O(n)
Space Complexity : O(1)