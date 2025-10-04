import java.util.Scanner;

class Node {
    int key;
    Node left, right;

    public Node(int item) {
        key = item;
        left = right = null;
    }
}

class BinarySearchTree {
    Node root;

    // Constructor
    BinarySearchTree() {
        root = null;
    }

    // Insert a key
    void insert(int key) {
        root = insertRec(root, key);
    }

    Node insertRec(Node root, int key) {
        // If tree is empty
        if (root == null) {
            root = new Node(key);
            return root;
        }

        // Otherwise, recur down the tree
        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);

        // return the (unchanged) node pointer
        return root;
    }

    // Search a key
    boolean search(int key) {
        return searchRec(root, key);
    }

    boolean searchRec(Node root, int key) {
        if (root == null)
            return false;
        if (root.key == key)
            return true;
        return key < root.key ? searchRec(root.left, key) : searchRec(root.right, key);
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder() {
        inorderRec(root);
    }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.key + " ");
            inorderRec(root.right);
        }
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder() {
        preorderRec(root);
    }

    void preorderRec(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorderRec(root.left);
            preorderRec(root.right);
        }
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder() {
        postorderRec(root);
    }

    void postorderRec(Node root) {
        if (root != null) {
            postorderRec(root.left);
            postorderRec(root.right);
            System.out.print(root.key + " ");
        }
    }

    // Delete a key
    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

    Node deleteRec(Node root, int key) {
        if (root == null) return root;

        if (key < root.key)
            root.left = deleteRec(root.left, key);
        else if (key > root.key)
            root.right = deleteRec(root.right, key);
        else {
            // Node with one or no child
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            // Node with two children: Get inorder successor (smallest in right subtree)
            root.key = minValue(root.right);

            // Delete the inorder successor
            root.right = deleteRec(root.right, root.key);
        }

        return root;
    }

    // Get minimum value in tree
    int minValue(Node root) {
        int minv = root.key;
        while (root.left != null) {
            minv = root.left.key;
            root = root.left;
        }
        return minv;
    }

    // Get maximum value in tree
    int maxValue(Node root) {
        int maxv = root.key;
        while (root.right != null) {
            maxv = root.right.key;
            root = root.right;
        }
        return maxv;
    }
}

//Sample implementation
public class BSTDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BinarySearchTree tree = new BinarySearchTree();

        System.out.println("Enter number of elements to insert into BST:");
        int n = sc.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            tree.insert(val);
        }

        System.out.println("\nInorder traversal: ");
        tree.inorder();

        System.out.println("\nPreorder traversal: ");
        tree.preorder();

        System.out.println("\nPostorder traversal: ");
        tree.postorder();

        System.out.print("\n\nEnter element to search: ");
        int key = sc.nextInt();
        System.out.println(tree.search(key) ? "Found!" : "Not found!");

        System.out.print("\nEnter element to delete: ");
        int delKey = sc.nextInt();
        tree.deleteKey(delKey);

        System.out.println("Inorder traversal after deletion: ");
        tree.inorder();

        System.out.println("\nMinimum value in BST: " + tree.minValue(tree.root));
        System.out.println("Maximum value in BST: " + tree.maxValue(tree.root));

        sc.close();
    }
}
