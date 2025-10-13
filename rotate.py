def rotate_slicing(arr, k):
    """
    Rotates an array to the right by k steps using list slicing.
    
    :param arr: The list of elements to rotate.
    :param k: The number of steps to rotate.
    :return: A new list that is the rotated version of arr.
    """
    if not arr:
        return []
        
    n = len(arr)
    # Handle cases where k is larger than the array length
    k = k % n
    
    if k == 0:
        return arr
        
    # Get the last k elements and the first n-k elements
    rotated_arr = arr[-k:] + arr[:-k]
    
    return rotated_arr

# --- Example Usage ---
my_array = [1, 2, 3, 4, 5, 6, 7]
k = 3
rotated = rotate_slicing(my_array, k)
print(f"Original array: {my_array}")
print(f"Rotated array:  {rotated}")
# Output: Rotated array:  [5, 6, 7, 1, 2, 3, 4]

# Example with k > len(arr)
my_array_2 = [1, 2, 3]
k_2 = 5 # Rotating by 5 is the same as rotating by 5 % 3 = 2
rotated_2 = rotate_slicing(my_array_2, k_2)
print(f"\nOriginal array: {my_array_2}")
