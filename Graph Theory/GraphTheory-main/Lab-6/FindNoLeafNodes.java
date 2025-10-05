//  Prob. 1 Given the root of a binary tree, return its maximum depth. 
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to 
// the farthest leaf node. 
// Input: root = [3,9,20,null,null,15,7] 
// Output: 3 
// Prob. 2 Identify all pendent (leaf) vertices in a given tree. 
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

public class FindNoLeafNodes {

    public static void main(String[] args) {
        int [] arr = { 3, 9, 20, -1, -1, 15, 7}; //  null represent with -1
        System.out.print("Tree (Inorder): ");
        Node root = createTreeFromArray(arr);
        PrintTree(root);
        int depth = FindMaxDepth(root);
        System.out.println("depth : " + depth);
        PrintLeafNodes(root);
    }

    public static Node createTreeFromArray(int[] arr) {
        // if the length of array is 0
        // or the first means root node is null then not need to further process
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

    public static void PrintLeafNodes(Node root){
        if( root == null ) return;

        if(root.left == null && root.right == null){
            System.out.print(root.value+" ");
        } 
        PrintLeafNodes(root.left);
        PrintLeafNodes(root.right);
    }
    
    public static void PrintTree(Node root) {
        if (root == null) return;

        PrintTree(root.left);
        System.out.print(root.value + " ");
        PrintTree(root.right);
    }

    static int FindMaxDepth(Node root) {
        if (root == null)
            return 0;

        int leftDepth = FindMaxDepth(root.left);
        int rightDepth = FindMaxDepth(root.right);

        return Math.max(leftDepth, rightDepth) + 1;
    }
}
