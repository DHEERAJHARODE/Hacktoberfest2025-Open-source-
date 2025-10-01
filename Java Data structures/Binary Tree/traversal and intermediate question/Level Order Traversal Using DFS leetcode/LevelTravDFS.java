import java.util.LinkedList;
import java.util.Queue;

class TreeNode {// we can do the traversal using DFS by using Calculate Nth level function And
                // Calculate Nth level function........
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class LevelTravDFS {
    public static int CalcLevel(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(CalcLevel(root.left), CalcLevel(root.right));
    }

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
        // printing all the elements using DFS........................
        int totalLevel = CalcLevel(root);
        for (int i = 0; i < totalLevel; i++) {
            NthLevelElem(root, i, 0);
            System.out.println();
        }
    }
}