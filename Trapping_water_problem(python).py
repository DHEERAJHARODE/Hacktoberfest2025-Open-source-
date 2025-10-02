#Trapping water problem(Python)
'''You are given an array height[] of non-negative integers. Each integer represents the height of a bar in an elevation map, where the width of each bar is 1.

When it rains, water can get trapped between the bars if there are taller bars on both the left and right sides of a shorter bar.
Your task is to calculate how much total water can be trapped between the bars.'''

#CODE
def trap(height):
    n = len(height)
    if n == 0:
        return 0
    
    left, right = 0, n - 1
    left_max, right_max = 0, 0
    water = 0
    
    while left < right:
        if height[left] < height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1
    
    return water

''' Example usage:
print(trap([0,1,0,2,1,0,1,3,2,1,2,1]))  # Output: 6''' #u can check with this particular sample
