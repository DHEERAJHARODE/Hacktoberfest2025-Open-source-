// BinarySearchTreeAdvanced.java
// Author: Riya Joshi
// Hacktoberfest 2025 Contribution

import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class BinarySearchTreeAdvanced {
    Node root;

    // 1️⃣ Insert a node
    void insert(int key) {
        root = insertRec(root, key);
    }

    Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.data) root.left = insertRec(root.left, key);
        else if (key > root.data) root.right = insertRec(root.right, key);
        return root;
    }

    // 2️⃣ Delete a node
    void delete(int key) {
        root = deleteRec(root, key);
    }

    Node deleteRec(Node root, int key) {
        if (root == null) return root;

        if (key < root.data) root.left = deleteRec(root.left, key);
        else if (key > root.data) root.right = deleteRec(root.right, key);
        else {
            // Node with only one child or no child
            if (root.left == null) return root.right;
            else if (root.right == null) return root.left;

            // Node with two children: Get inorder successor (smallest in the right subtree)
            root.data = minValue(root.right);

            // Delete the inorder successor
            root.right = deleteRec(root.right, root.data);
        }
        return root;
    }

    int minValue(Node root) {
        int minv = root.data;
        while (root.left != null) {
            minv = root.left.data;
            root = root.left;
        }
        return minv;
    }

    // 3️⃣ Find a node
    boolean find(int key) {
        return findRec(root, key);
    }

    boolean findRec(Node root, int key) {
        if (root == null) return false;
        if (root.data == key) return true;
        return key < root.data ? findRec(root.left, key) : findRec(root.right, key);
    }

    // 4️⃣ Find middle element (in-order middle)
    int findMiddle() {
        List<Integer> inOrderList = new ArrayList<>();
        inorderCollect(root, inOrderList);
        if (inOrderList.isEmpty()) return -1; // Tree empty
        return inOrderList.get(inOrderList.size() / 2);
    }

    void inorderCollect(Node root, List<Integer> list) {
        if (root != null) {
            inorderCollect(root.left, list);
            list.add(root.data);
            inorderCollect(root.right, list);
        }
    }

    // 5️⃣ Find children of a parent
    void findChildren(int parent) {
        Node node = findNode(root, parent);
        if (node != null) {
            System.out.println("Parent: " + node.data);
            System.out.println("Left Child: " + (node.left != null ? node.left.data : "null"));
            System.out.println("Right Child: " + (node.right != null ? node.right.data : "null"));
        } else {
            System.out.println("Parent not found.");
        }
    }

    Node findNode(Node root, int key) {
        if (root == null || root.data == key) return root;
        return key < root.data ? findNode(root.left, key) : findNode(root.right, key);
    }

    // Traversals
    void inorder() { inorderRec(root); System.out.println(); }
    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }

    void preorder() { preorderRec(root); System.out.println(); }
    void preorderRec(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preorderRec(root.left);
            preorderRec(root.right);
        }
    }

    void postorder() { postorderRec(root); System.out.println(); }
    void postorderRec(Node root) {
        if (root != null) {
            postorderRec(root.left);
            postorderRec(root.right);
            System.out.print(root.data + " ");
        }
    }

    // ✅ Main method to test everything
    public static void main(String[] args) {
        BinarySearchTreeAdvanced bst = new BinarySearchTreeAdvanced();
        int[] values = {50, 30, 70, 20, 40, 60, 80};

        // Insert values
        for (int v : values) bst.insert(v);

        System.out.print("Inorder: "); bst.inorder();
        System.out.print("Preorder: "); bst.preorder();
        System.out.print("Postorder: "); bst.postorder();

        // Find a node
        System.out.println("Find 40? " + bst.find(40));

        // Delete a node
        bst.delete(70);
        System.out.print("After deleting 70, inorder: "); bst.inorder();

        // Find middle element
        System.out.println("Middle element (in-order): " + bst.findMiddle());

        // Find children of 30
        bst.findChildren(30);
    }
}
