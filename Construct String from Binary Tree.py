class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        def preorder(node):
            if not node:
                return ""
            
            result = str(node.val)
            
            if node.left or node.right:
                result += "(" + preorder(node.left) + ")"
            
            if node.right:
                result += "(" + preorder(node.right) + ")"
            
            return result
        
        return preorder(root)
