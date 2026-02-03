Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

//https://leetcode.com/problems/longest-valid-parentheses/

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        queue = collections.deque()
        queue.append(0)
        longest = 0
        for p in s:
            if p == '(':
                queue.append(0)
            if p == ')':
                if len(queue) > 1:
                    length = queue.pop() + 2
                    queue[-1] += length
                    longest = max(longest, queue[-1])
                else:
                    queue[-1] = 0
        return longest
