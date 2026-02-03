class Node:
    def __init__(self, val=None, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

def cloneGraph(node):
    if not node:
        return None

    # Use a dictionary to keep track of original nodes and their corresponding clones
    node_map = {}

    # Start DFS traversal
    return cloneNode(node, node_map)

def cloneNode(node, node_map):
    # If the node has already been cloned, return its clone
    if node in node_map:
        return node_map[node]

    # Create a clone of the current node
    clone = Node(node.val)
    node_map[node] = clone

    # Recursively clone the neighbors of the current node
    for neighbor in node.neighbors:
        clone.neighbors.append(cloneNode(neighbor, node_map))

    return clone

def printGraph(node, visited):
    if not node or node in visited:
        return

    visited.add(node)
    neighbors = [neighbor.val for neighbor in node.neighbors]
    print(f"Node {node.val}: {neighbors}")

    for neighbor in node.neighbors:
        printGraph(neighbor, visited)

# Example usage
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)

node1.neighbors.extend([node2, node3])
node2.neighbors.extend([node1, node3])
node3.neighbors.extend([node1, node2])

cloned_node1 = cloneGraph(node1)

# Print the cloned graph (for demonstration)
print("Original graph:")
printGraph(node1, set())
print("Cloned graph:")
printGraph(cloned_node1, set())
