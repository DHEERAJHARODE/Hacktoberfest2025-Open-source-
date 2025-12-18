class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return (nums[-1] * nums[-2]) - (nums[0] * nums[1])
        
sol = Solution()
output1 = sol.maxProductDifference([5, 6, 2, 7, 4])
output2 = sol.maxProductDifference([4, 2, 5, 9, 7, 4, 8])

print(output1, output2)
