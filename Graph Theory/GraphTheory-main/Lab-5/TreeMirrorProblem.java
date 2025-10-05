/*
Prob.  1 Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its 
center). 
Input: root = [1,2,2,3,4,4,3]
Output: true 
Input: root = [1,2,2,null,3,null,3] 
Output: false
*/

import java.util.*;

class Node {
    int value;
    Node left, right;

    public Node(int data) {
        this.value = data;
        this.left = null;
        this.right = null;
    }
}

public class TreeMirrorProblem {
    public static void main(String[] args) {
        int arr1[] = {1, 2, 2, 3, 4, 4, 3};
        Node root1 = createTreeFromArray(arr1);

        System.out.print("Tree 1 (Inorder): ");
        printTree(root1);
        System.out.println("\nIs Mirror : " + isSymmetric(root1));

        int arr2[] = {1, 2, 2, -1, 3, -1, 3}; // use -1 for nulls
        Node root2 = createTreeFromArray(arr2);
        System.out.print("\nTree 2 (Inorder): ");
        printTree(root2);
        System.out.println("\nIs Mirror : " + isSymmetric(root2));
    }

    // Use -1 to represent null in array
    public static Node createTreeFromArray(int[] arr) {
        if (arr.length == 0 || arr[0] == -1) return null;

        Node root = new Node(arr[0]);
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        int i = 1;
        while (i < arr.length) {
            Node current = queue.poll();

            if (i < arr.length && arr[i] != -1) {
                current.left = new Node(arr[i]);
                queue.add(current.left);
            }
            i++;

            if (i < arr.length && arr[i] != -1) {
                current.right = new Node(arr[i]);
                queue.add(current.right);
            }
            i++;
        }

        return root;
    }

    public static boolean isSymmetric(Node root) {
        if (root == null) return true;
        return isMirror(root.left, root.right);
    }

    public static boolean isMirror(Node t1, Node t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.value == t2.value) &&
               isMirror(t1.left, t2.right) &&
               isMirror(t1.right, t2.left);
    }

    public static void printTree(Node root) {
        if (root == null) return;

        printTree(root.left);
        System.out.print(root.value + " ");
        printTree(root.right);
    }
}
