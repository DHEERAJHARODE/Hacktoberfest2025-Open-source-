// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// Example 1:

// Input: N = 5, array[] = {1,2,2,3,2}

// Ouput: 2

// Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

// Example 2:

// Input:  N = 6, array[] = {11,33,33,11,33,11}

// Output: 11 33

// Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.


// Approach : In our code, we start with declaring a few variables:

// num1 and num2 will store our currently most frequent and second most frequent element.
// c1 and c2 will store their frequency relatively to other numbers.
// We are sure that there will be a max of 2 elements which occurs > N/3 times because there cannot be if you do a simple math addition.
// Let, ele be the element present in the array at any index. 

// if ele == num1, so we increment c1.
// if ele == num2, so we increment c2.
// if c1 is 0, so we assign num1 = ele.
// if c2 is 0, so we assign num2 = ele.
// In all the other cases we decrease both c1 and c2.
// In the last step, we will run a loop to check if num1 or nums2 are the majority elements or not by running a for loop check.

// Code 

#include <bits/stdc++.h>

using namespace std;
vector < int > majorityElement(int nums[], int n) {
  int sz = n;
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}

int main() {
  int arr[] = {1,2,2,3,2};
  vector < int > majority;
  majority = majorityElement(arr, 5);
  cout << "The majority element is ";

  for (auto it: majority) {
    cout << it << " ";
  }
}

Time Complexity: O(n)

Space Complexity: O(1)