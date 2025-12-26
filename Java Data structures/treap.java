import java.util.Random;

class Node {
    int key;
    int priority;
    Node left;
    Node right;
}

public class Treap {
    private Node createNode(int key) {
        Node newNode = new Node();
        newNode.key = key;
        newNode.priority = new Random().nextInt();
        newNode.left = newNode.right = null;
        return newNode;
    }

    private Node rotateRight(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        return x;
    }

    private Node rotateLeft(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        y.left = x;
        x.right = T2;

        return y;
    }

    private Node insert(Node root, int key) {
        if (root == null) return createNode(key);

        if (key <= root.key) {
            root.left = insert(root.left, key);
            if (root.left.priority > root.priority)
                root = rotateRight(root);
        } else {
            root.right = insert(root.right, key);
            if (root.right.priority > root.priority)
                root = rotateLeft(root);
        }

        return root;
    }

    private void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print("(" + root.key + ", " + root.priority + ") ");
            inorderTraversal(root.right);
        }
    }

    public static void main(String[] args) {
        Node root = null;

        Treap treap = new Treap();
        root = treap.insert(root, 50);
        root = treap.insert(root, 30);
        root = treap.insert(root, 20);
        root = treap.insert(root, 40);
        root = treap.insert(root, 70);
        root = treap.insert(root, 60);
        root = treap.insert(root, 80);

        System.out.println("Inorder traversal of the treap:");
        treap.inorderTraversal(root);
        System.out.println();
    }
}
