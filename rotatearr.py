class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n= len(nums)
        a1 = [0]*n
        for i in range(len(nums)):
            j = (i+k) % n
            a1[j] = nums[i]
        
        for i in range(n):
            nums[i] = a1[i]
