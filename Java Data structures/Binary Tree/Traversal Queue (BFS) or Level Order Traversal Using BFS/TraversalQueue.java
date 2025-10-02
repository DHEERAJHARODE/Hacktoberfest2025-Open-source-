import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class TraversalQueue {
    public static void levelOrderLeftToright(TreeNode root) {// breath first search traversal using
        // queue.........................left to right............
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            if (q.peek().left != null)
                q.add(q.peek().left);
            if (q.peek().right != null)
                q.add(q.peek().right);
            System.out.print(q.remove().val + " ");
        }
        System.out.println();
    }

    public static void levelOrderrightToLeft(TreeNode root) {// breath first search traversal using
        // queue.........................right to left............
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            if (q.peek().right != null)
                q.add(q.peek().right);
            if (q.peek().left != null)
                q.add(q.peek().left);
            System.out.print(q.remove().val + " ");
        }
        System.out.println();
    }

    public static void displayPreorder(TreeNode root) {
        if (root == null)
            return;
        System.out.print(root.val + " ");
        displayPreorder(root.left);
        displayPreorder(root.right);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode b = new TreeNode(2);
        TreeNode c = new TreeNode(3);
        TreeNode d = new TreeNode(4);
        TreeNode e = new TreeNode(5);
        TreeNode f = new TreeNode(6);
        TreeNode g = new TreeNode(7);
        root.left = b;
        root.right = c;
        b.left = d;
        b.right = e;
        c.left = f;
        c.right = g;
        levelOrderLeftToright(root);// left to right.........
        levelOrderrightToLeft(root);// right to left...........
    }
}