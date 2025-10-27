/**
 * Maximum Number of Distinct Elements After Operations - LeetCode #3184
 *
 * Problem Description:
 * Given an integer array `nums` and an integer `k`, you can perform the following operation any number of times:
 * - Choose any element `nums[i]` and add any integer in the range `[-k, k]` to it
 * The goal is to maximize the number of distinct elements in the array after performing operations.
 *
 * Approach: Greedy Strategy with Sorting
 * 1. Sort the array to process elements in ascending order
 * 2. For each element, try to assign the smallest possible unique value within its allowed range
 * 3. Track the next available smallest unique value to assign
 * 4. If a valid assignment is possible, increment the count of distinct elements
 *
 * Time Complexity: O(n log n) - dominated by sorting
 * Space Complexity: O(1) - excluding the input storage
 *
 * Key Insight:
 * Each element nums[i] can be transformed to any value in [nums[i]-k, nums[i]+k]
 * We want to assign each element to the smallest possible unique integer
 * This transforms the problem into assigning unique values from sorted intervals
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
  int maxDistinctElements(vector<int> &nums, int k)
  {
    // Sort the array to process elements in ascending order
    sort(nums.begin(), nums.end());

    int distinctCount = 0;
    long long currentMin = -1e10; // Track the next available smallest unique value

    for (int num : nums)
    {
      // Calculate the minimum value we can assign to this element
      // It should be at least (num - k) and greater than previous assigned values
      long long assignValue = max((long long)num - k, currentMin);

      // Check if the assigned value is within the allowed range [num-k, num+k]
      if (assignValue <= (long long)num + k)
      {
        distinctCount++;
        currentMin = assignValue + 1; // Next available unique value
      }
    }

    return distinctCount;
  }
};

// Alternative implementation with more detailed comments
class DetailedSolution
{
public:
  int maxDistinctElements(vector<int> &nums, int k)
  {
    /**
     * Greedy Approach:
     * 1. Sort the array to process numbers in increasing order
     * 2. For each number, we try to assign the smallest possible unique value
     * 3. The assigned value must be within [num-k, num+k]
     * 4. We track the next available smallest unique value
     */

    if (nums.empty())
      return 0;

    sort(nums.begin(), nums.end());

    int result = 0;
    long long nextAvailable = LLONG_MIN; // Start with very small value

    for (int i = 0; i < nums.size(); i++)
    {
      long long currentNum = nums[i];

      // The range of possible values for current element
      long long minPossible = currentNum - k;
      long long maxPossible = currentNum + k;

      // We want to assign the smallest unique value possible
      // It should be at least the minimum possible and greater than previous assignments
      long long assignCandidate = max(minPossible, nextAvailable);

      // If the candidate is within the allowed range, we can assign it
      if (assignCandidate <= maxPossible)
      {
        result++;
        nextAvailable = assignCandidate + 1; // Next unique value
      }
      // If not possible to assign a unique value, skip this element
    }

    return result;
  }
};

// Test function to verify the solution
void testSolution()
{
  Solution sol;

  // Test case 1: Basic example
  vector<int> nums1 = {2, 4, 6, 8};
  int k1 = 1;
  cout << "Test 1 - Input: [2,4,6,8], k=1" << endl;
  cout << "Output: " << sol.maxDistinctElements(nums1, k1) << " (Expected: 4)" << endl;
  cout << endl;

  // Test case 2: All same elements with sufficient k
  vector<int> nums2 = {5, 5, 5, 5};
  int k2 = 2;
  cout << "Test 2 - Input: [5,5,5,5], k=2" << endl;
  cout << "Output: " << sol.maxDistinctElements(nums2, k2) << " (Expected: 4)" << endl;
  cout << endl;

  // Test case 3: Limited k value
  vector<int> nums3 = {1, 2, 3, 4};
  int k3 = 0;
  cout << "Test 3 - Input: [1,2,3,4], k=0" << endl;
  cout << "Output: " << sol.maxDistinctElements(nums3, k3) << " (Expected: 4)" << endl;
  cout << endl;

  // Test case 4: Mixed scenario
  vector<int> nums4 = {3, 3, 3, 5, 5, 7};
  int k4 = 1;
  cout << "Test 4 - Input: [3,3,3,5,5,7], k=1" << endl;
  cout << "Output: " << sol.maxDistinctElements(nums4, k4) << " (Expected: 6)" << endl;
  cout << endl;

  // Test case 5: Single element
  vector<int> nums5 = {10};
  int k5 = 5;
  cout << "Test 5 - Input: [10], k=5" << endl;
  cout << "Output: " << sol.maxDistinctElements(nums5, k5) << " (Expected: 1)" << endl;
  cout << endl;

  // Test case 6: Large k value
  vector<int> nums6 = {1, 100};
  int k6 = 50;
  cout << "Test 6 - Input: [1,100], k=50" << endl;
  cout << "Output: " << sol.maxDistinctElements(nums6, k6) << " (Expected: 2)" << endl;
}

// Main function
int main()
{
  cout << "Testing Maximum Number of Distinct Elements After Operations - LeetCode #3184" << endl;
  cout << "====================================================================" << endl;
  testSolution();
  return 0;
}