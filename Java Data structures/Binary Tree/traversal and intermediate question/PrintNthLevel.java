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

public class PrintNthLevel {
    public static void NthLevelElem(TreeNode root, int n, int count) {
        if (root == null)
            return;
        if (count == n) {
            System.out.print(root.val + " ");
            return;
        }
        NthLevelElem(root.left, n, count + 1);
        NthLevelElem(root.right, n, count + 1);
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
        NthLevelElem(root, 2, 0);
    }
}
