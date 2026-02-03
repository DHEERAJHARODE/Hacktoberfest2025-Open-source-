# Problem Statement:  Given an array of integers and an integer number, return indices of
#                     the two numbers such that they add up to the given target
# Example:
#
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

# the below code of "TWOSUM" is done in O(nlogn). The left and right pointer perform O(n) steps,
# the time complexity is O(n), but the sorting step makes it O(nlogn).

# the code is ------------------------------------------------------------------------

def two_sum(arr, res):

    #  index of sorted array/list
    a = sorted(range(len(nums)), key=lambda k: arr[k])

    # initialize the left and right
    left = 0
    right = len(arr) - 1

    # two pointers check for a sorted list/array
    while (left < right):

        left = a[left]
        right = a[right]

        if arr[left] + arr[right] == res:
            return [left, right]

        if arr[left] + arr[right] > res:
            right = right - 1
        else:
            left = left + 1

    return []

nums = [2,7,11,15]
target = 17

x = two_sum(nums, target)
print(x)

# answer will be [0, 3] 😊😊😊😊😊😊
# Hope you will understand **************************************************************
