# Function to perform binary search
def binarySearch(arr, left, right, target):
    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return False

def twoSum(arr, target):
    arr.sort()

    for i in range(len(arr)):
        complement = target - arr[i]

        # Use binary search to find the complement
        if binarySearch(arr, i + 1,
                    len(arr) - 1, complement):
            return True
            
    # If no pair is found
    return False
  	
if __name__ == "__main__":
    arr = [0, -1, 2, -3, 1]
    target = -2

    if twoSum(arr, target):
        print("true")
    else:
        print("false")
