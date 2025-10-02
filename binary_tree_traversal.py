class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        if not self.root:
            self.root = Node(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = Node(value)
            else:
                self._insert_recursive(node.left, value)
        else:
            if node.right is None:
                node.right = Node(value)
            else:
                self._insert_recursive(node.right, value)

    def inorder_traversal(self):
        """Left -> Root -> Right"""
        result = []
        self._inorder_recursive(self.root, result)
        return result

    def _inorder_recursive(self, node, result):
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.value)
            self._inorder_recursive(node.right, result)

    def preorder_traversal(self):
        """Root -> Left -> Right"""
        result = []
        self._preorder_recursive(self.root, result)
        return result

    def _preorder_recursive(self, node, result):
        if node:
            result.append(node.value)
            self._preorder_recursive(node.left, result)
            self._preorder_recursive(node.right, result)

    def postorder_traversal(self):
        """Left -> Right -> Root"""
        result = []
        self._postorder_recursive(self.root, result)
        return result

    def _postorder_recursive(self, node, result):
        if node:
            self._postorder_recursive(node.left, result)
            self._postorder_recursive(node.right, result)
            result.append(node.value)

def main():
    # Create a binary tree and insert some values
    tree = BinaryTree()
    values = [5, 3, 7, 1, 4, 6, 8]
    
    print("Creating a binary tree with values:", values)
    for value in values:
        tree.insert(value)
    
    # Demonstrate all three traversal methods
    print("\nInorder Traversal (Left -> Root -> Right):", tree.inorder_traversal())
    print("Preorder Traversal (Root -> Left -> Right):", tree.preorder_traversal())
    print("Postorder Traversal (Left -> Right -> Root):", tree.postorder_traversal())

if __name__ == "__main__":
    main()