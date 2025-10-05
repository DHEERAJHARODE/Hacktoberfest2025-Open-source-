import java.util.*;

class Node {
    int value;
    Node left;
    Node right;

    public Node(int data) {
        this.value = data;
        this.left = null;
        this.right = null;
    }
}

public class TreeMirrorProblem2 {

    public static void main(String[] args) {
        int[] arr = {1, 2, 2, 3, 4, 4, 3};
        Node root = null;

        for (int i = 0; i < arr.length; i++) {
            Node temp = new Node(arr[i]);
            root = treeGenerate(root, temp);
        }

        System.out.println("In-order Traversal:");
        inOrderTraversal(root);
        
        boolean result = isMirror(root.left, root.right);
        System.out.println("\nIs Mirror Tree: " + result);
    }

    // Insert nodes in level-order (BFS)
    static Node treeGenerate(Node root, Node newNode) {
        if (root == null) {
            return newNode;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node temp = queue.poll();

            if (temp.left == null) {
                temp.left = newNode;
                return root;
            } else {
                queue.add(temp.left);
            }

            if (temp.right == null) {
                temp.right = newNode;
                return root;
            } else {
                queue.add(temp.right);
            }
        }

        return root;
    }

    // In-order Traversal
    static void inOrderTraversal(Node root) {
        if (root == null) {
            return;
        }

        inOrderTraversal(root.left);
        System.out.print(root.value + " ");
        inOrderTraversal(root.right);
    }

    // Check if two subtrees are mirror of each other
    static boolean isMirror(Node node1, Node node2) {
        if (node1 == null && node2 == null)
            return true;

        if (node1 != null && node2 != null && node1.value == node2.value)
            return isMirror(node1.left, node2.right) && isMirror(node1.right, node2.left);

        return false;
    }
}
