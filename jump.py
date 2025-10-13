def jump(nums: list[int]) -> int:
    jumps = 0          # Number of jumps taken
    cur_end = 0        # End of the current jump range
    farthest = 0       # Farthest we can reach with the next jump
    
    for i in range(len(nums) - 1):  # No need to jump from the last index
        farthest = max(farthest, i + nums[i])
        
        # When we reach the end of the current jump range
        if i == cur_end:
            jumps += 1
            cur_end = farthest  # Extend range to farthest point we can reach
            
    return jumps
