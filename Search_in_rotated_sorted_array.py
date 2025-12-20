# There is an integer array nums sorted in ascending order (with distinct values).

# Prior to being passed to your function, nums is possibly rotated 
# at an unknown pivot index k (1 <= k < nums.length) 
# such that the resulting array is 
# [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
# For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

# Given the array nums after the possible rotation and an integer target,
#  return the index of target if it is in nums, or -1 if it is not in nums.

# You must write an algorithm with O(log n) runtime complexity.

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left=0
        right=len(nums)-1
        flag=-1
        if left==right:
            if target==nums[left]:
                flag=left
        while(left<right):
            mid=(left+right)//2
            # print(left,right,mid)
            if nums[left]==target:
                flag=left
                break
                
            if nums[right]==target:
                flag=right
                break
                
            if nums[mid]==target:
                flag=mid
                break
                
            elif target>nums[left] and target>nums[right] and target>nums[mid]:
                if nums[mid]>nums[right]:
                    left=mid+1
                else:
                    right=mid-1
                    
            elif target>nums[left] and target>nums[right] and target<nums[mid]:
                right=mid-1
                
            elif target>nums[left] and target<nums[right] and target<nums[mid]:
                right=mid-1
            elif target>nums[left] and target<nums[right] and target>nums[mid]:
                left=mid+1
                
            elif target<nums[left] and target<nums[right] and target<nums[mid]:
                # left=mid+1
                # 
                if nums[mid]>nums[right]:
                    left=mid+1
                else:
                    right=mid-1
            elif target<nums[left] and target<nums[right] and target>nums[mid]:
                if nums[mid]>nums[right]:
                    right=mid-1
                else:
                    left=mid+1
                    
                
            elif target<nums[left] and target>nums[right]:
                break
                
            
        return(flag)
            
        