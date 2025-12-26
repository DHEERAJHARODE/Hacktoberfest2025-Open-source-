def trap(arr):
    if len(arr) == 0:
        return 0

    l, r = 0, len(arr) - 1
    l_max, r_max = 0, 0
    result = 0

    while l < r:
        if arr[l] < arr[r]:
            if arr[l] >= l_max:
                l_max = arr[l]
            else:
                result += l_max - arr[l]
            l += 1
        else:
            if arr[r] >= r_max:
                r_max = arr[r]
            else:
                result += r_max - arr[r]
            r -= 1

    return result

# arr = [0,1,0,2,1,0,1,3,2,1,2,1]
# print(trap(arr)) # 6
