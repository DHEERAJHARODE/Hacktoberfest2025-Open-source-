from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""
        
        t_count = Counter(t)
        window_count = {}
        
        have, need = 0, len(t_count)
        res, res_len = [-1, -1], float("inf")
        
        left = 0
        for right, char in enumerate(s):
            # Add character to window
            window_count[char] = window_count.get(char, 0) + 1
            
            # Check if current char satisfies the frequency requirement
            if char in t_count and window_count[char] == t_count[char]:
                have += 1
            
            # Try to shrink window from left side
            while have == need:
                # Update result
                if (right - left + 1) < res_len:
                    res = [left, right]
                    res_len = right - left + 1
                
                # Remove leftmost char
                window_count[s[left]] -= 1
                if s[left] in t_count and window_count[s[left]] < t_count[s[left]]:
                    have -= 1
                left += 1
        
        l, r = res
        return s[l:r+1] if res_len != float("inf") else ""
