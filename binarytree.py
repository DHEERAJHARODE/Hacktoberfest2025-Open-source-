# The Node Class defines the structure of a Node
class Node:
    # Initialize the attributes of Node
    def __init__(self, data):
        self.left = None # Left Child
        self.right = None # Right Child
        self.data = data # Node Data
        root = Node(10) # Instantiating the Tree
# Tree Structure
#        10
#      /    \
#     None   None

root.left = Node(34) # Setting the left child of the root to 34
root.right = Node(89) # Setting the right child of the root to 89

# Tree Structure
#          10
#        /    \
#       34      89
#     /    \  /    \
#  None  None None None

# Inorder traversal
def inorder(node):
    if node:
        # Recursively call inorder on the left subtree until it reaches a leaf node
        inorder(node.left)

        # Once we reach a leaf, we print the data
        print(node.data)

        # Now, since the left subtree and the root has been printed, call inorder on right subtree recursively until we reach a leaf node.
        inorder(node.right)

# For the tree,
#          10
#        /    \
#       34      89
#     /    \  /    \
#  20     45  56    54

# Inorder traversal: 20 34 45 10 56 89 54

# Preorder traversal:
def preorder(node):
    if node:
        # Print the value of the root node first
        print(node.data)

        # Recursively call preorder on the left subtree until we reach a leaf node.
        preorder(node.left)

        # Recursively call preorder on the right subtree until we reach a leaf node.
        preorder(node.right)

# For the tree,
#          10
#        /    \
#       34      89
#     /    \  /    \
#  20     45  56    54

# Preorder traversal: 10 34 20 45 89 56 54


# Postorder traversal:
def postorder(node):
    if node:
        # Recursively call postorder on the left subtree until we reach a leaf node.
        postorder(node.left)

        # Recursively call postorder on the right subtree until we reach a leaf node.
        postorder(node.right)

        # Print the value of the root node
        print(node.data)

# For the tree,
#          10
#        /    \
#       34      89
#     /    \  /    \
#  20     45  56    54

# Postorder traversal: 20 45 34 56 54 89 10
