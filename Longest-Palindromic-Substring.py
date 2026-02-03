class Solution(object):
    def longestPalindrome(self, s):
        
        def helper(s, l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            l += 1
            r -= 1
            
            return ((r - l) + 1, l, r)
        
        longest = left = right = 0
        
        for i in range(len(s)):
            for j in range(2):
                length, l, r = helper(s, i, i + j)
                if length > longest:
                    longest = length
                    right = r
                    left = l
                    
        return s[left : right + 1]
