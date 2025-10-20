/*
 * Algorithm: Jump Search
 * Description: Jump Search is an improvement over linear search for sorted
 * arrays. It works by dividing the array into blocks of fixed size (usually √n)
 *               and jumping ahead by that block size until the target is found
 * or passed, after which a linear search is done within the block. Time
 * Complexity : Best Case : O(1)  // when the element is found in the first jump
 *     Average Case : O(√n) // due to jumping and linear scan
 *     Worst Case : O(√n) // when the element is at the end or not present
 * Space Complexity:
 *   Worst : O(1)
 * Author: Abhiram
 */
#include <stdio.h>

/*
 * int_int_sqrt : Calculates the integer square root of a non-negative integer
 * x.
 * @param x: The number to find the square root of
 * @return: The floor of the square root of x
 */
int int_sqrt(int x) {
  if (x == 0 || x == 1)
    return x;

  int start = 1, end = x, ans = 0;
  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (mid <= x / mid) {
      start = mid + 1;
      ans = mid;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}

/*
 * jump_search : Searches for a target value in a sorted array using jump search
 * @param arr: Sorted array to search
 * @param size: Size of the array
 * @param target: Value to search for
 * @return: Index of the target if found, otherwise -1
 */
int jump_search(int arr[], int size, int target) {
  int step = int_sqrt(size);
  int prev = 0;

  while (arr[(step < size ? step : size) - 1] < target) {
    prev = step;
    step += int_sqrt(size);
    if (prev >= size)
      return -1;
  }

  for (int i = prev; i < step && i < size; i++) {
    if (arr[i] == target)
      return i;
  }

  return -1;
}

/*
 * print_result : Prints the result of the search
 * @param index: Index returned by jump_search
 * @param target: The target value searched
 */
void print_result(int index, int target) {
  if (index != -1)
    printf("Element %d found at index %d.\n", target, index);
  else
    printf("Element %d not found in the array.\n", target);
}

/*
 * test_algorithm: Tests the jump_search algorithm with multiple cases
 */
void test_algorithm() {

  // Test Case 1 : Element in the middle
  int test_arr1[] = {1, 3, 5, 7, 9, 11, 13, 15};
  int size1 = sizeof(test_arr1) / sizeof(test_arr1[0]);
  int target1 = 7;
  printf("Test 1 : ");
  print_result(jump_search(test_arr1, size1, target1), target1);

  // Test Case 2 : Element at the beginning
  int test_arr2[] = {2, 4, 6, 8, 10};
  int size2 = sizeof(test_arr2) / sizeof(test_arr2[0]);
  int target2 = 2;
  printf("Test 2 : ");
  print_result(jump_search(test_arr2, size2, target2), target2);

  // Test Case 3 : Element not in array
  int test_arr3[] = {10, 20, 30, 40, 50};
  int size3 = sizeof(test_arr3) / sizeof(test_arr3[0]);
  int target3 = 25;
  printf("Test 3 : ");
  print_result(jump_search(test_arr3, size3, target3), target3);
}

int main() {
  printf("[--- JUMP SEARCH ---]\n\n");
  test_algorithm();
  return 0;
}
