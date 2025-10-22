list1 = [1, 2, 3, 66, 56, 45, 4, 404, 45]

# Initialize min, max, second_min, second_max
min_value = float('inf')        # Positive infinity (for min)
max_value = float('-inf')       # Negative infinity (for max)
second_min = float('inf')       # Positive infinity (for second min)
second_max = float('-inf')      # Negative infinity (for second max)

for num in list1:
    # Update min and second_min
    if num < min_value:
        second_min = min_value  # Update second_min before min
        min_value = num
    elif num < second_min and num != min_value:  # Update second_min if it's not equal to min_value
        second_min = num

    # Update max and second_max
    if num > max_value:
        second_max = max_value  # Update second_max before max
        max_value = num
    elif num > second_max and num != max_value:  # Update second_max if it's not equal to max_value
        second_max = num

# Check if second min and second max exist
if second_min == float('inf'):
    print("There is no second minimum value")
else:
    print("The second minimum value is:", second_min)

if second_max == float('-inf'):
    print("There is no second maximum value")
else:
    print("The second maximum value is:", second_max)
