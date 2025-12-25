class Solution:
    def __init__(self):
        self.ceil = None
    def getSuccessor(self, root, val):
        if root == None:
            return self.ceil
        if root.val == val:
            return self.getSuccessor(root.right,val)
        if root.val < val:
            return self.getSuccessor(root.right,val)
        if root.val > val:
            self.ceil = root
            return self.getSuccessor(root.left,val)
