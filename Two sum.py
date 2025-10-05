class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # Dictionary to store {number: index}
        num_map = {} 
        
        # Iterate through the array with both index and value
        for i, num in enumerate(nums):
            # Calculate the complement needed to reach the target
            complement = target - num
            
            # Check if the complement is already in the map
            if complement in num_map:
                # If found, return its index (stored in the map) and the current index
                return [num_map[complement], i]
            
            # If not found, add the current number and its index to the map
            num_map[num] = i
            
        # Per the problem description, a solution always exists, but we include this for completeness
        return []
