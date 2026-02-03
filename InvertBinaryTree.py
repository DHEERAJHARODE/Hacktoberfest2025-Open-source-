# Name: Piyush Gour
# Github: https://github.com/piyushg1
"""
https://leetcode.com/problems/invert-binary-tree/
226. Invert Binary Tree
Easy

9542

132

Add to List

Share
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
"""
# Definition for a binary tree node.
from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:
            self.invertTree(root.left)
            self.invertTree(root.right)
            root.left, root.right = self.swapnodes(root.left, root.right)
            # root.left, root.right = root.right, root.left
        return root

    def swapnodes(self, r1, r2):
        temp = r1
        r1 = r2
        r2 = temp
        return (r1, r2)


def levelorder(root):
    q = deque([root])

    while q:
        x = q.pop()
        print(x.val)

        if x.left:
            q.appendleft(x.left)
        if x.right:
            q.appendleft(x.right)


root = TreeNode(4,
                (TreeNode(2, TreeNode(1), TreeNode(3))),
                (TreeNode(7, TreeNode(6), TreeNode(9)))
                )
obj = Solution()
ans = obj.invertTree(root)
levelorder(ans)
