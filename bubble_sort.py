"""
Bubble Sort Algorithm in Python
--------------------------------
This program implements the Bubble Sort algorithm.

Bubble Sort repeatedly steps through the list, compares adjacent elements,
and swaps them if they are in the wrong order. This process is repeated
until the list is sorted.

Time Complexity:
    - Best Case: O(n) when the list is already sorted
    - Average Case: O(n²)
    - Worst Case: O(n²)
Space Complexity: O(1)
"""

def bubble_sort(arr):
    """
    Sorts a list in ascending order using Bubble Sort.
    
    Args:
        arr (list): The list of elements to be sorted.
    
    Returns:
        list: The sorted list.
    """
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # If no two elements were swapped in inner loop, list is sorted
        if not swapped:
            break
    return arr


if __name__ == "__main__":
    sample = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", sample)
    sorted_arr = bubble_sort(sample)
    print("Sorted array:", sorted_arr)
