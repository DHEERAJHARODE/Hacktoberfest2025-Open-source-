def Bubblesort(nums):
    for i in range(len(nums)-1,0,-1):
        for j in range(i):
            if nums[j]>nums[j+1]:
                swap = nums[j]
                nums[j] = nums[j+1]
                nums[j+1] = swap


nums = [25, 13, 38, 6, 70, 2]
Bubblesort(nums)

print(nums)
