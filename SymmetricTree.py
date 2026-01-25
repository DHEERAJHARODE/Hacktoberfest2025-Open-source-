class BinaryTree:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
        
def treeinput():
    data=int(input())
    if data==-1:
        return None
    root=BinaryTree(data)
    leftdata=treeinput()
    rightdata=treeinput()
    root.left=leftdata
    root.right=rightdata
    return root
        
def printTree(root):
    if root==None:
        return
    print(root.data,end=":")
    if root.left!=None:
        print("L",root.left.data,end=",")
    if root.right!=None:
        print("R",root.right.data,end="")
    print()
    printTree(root.left)
    printTree(root.right)

def isSymmetric(root):
        if not root:
            return True
        def check(left,right):
            
            if not left and not right:
                return True
            
            if not left or not right:
                return False
            
            return (left.data==right.data and check(left.left,right.right) and check(left.right,right.left))
    

        return check(root.left,root.right)

root=treeinput()
printTree(root)
if isSymmetric(root):
    print("THE TREE IS SYMMETRIC")
else:
    print("THE TREE IS NOT SYMMETRIC")
