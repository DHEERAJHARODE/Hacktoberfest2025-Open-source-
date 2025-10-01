import java.util.*;

class pair {
    TreeNode node;
    int level;

    pair(TreeNode node, int level) {
        this.node = node;
        this.level = level;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class BFSusingRecursion {
    private static int CalLevel(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(CalLevel(root.left), CalLevel(root.right));
    }

    private static TreeNode Traverse(TreeNode root, int level, int cal) {
        TreeNode ans = null;
        if (root == null)
            return root;
        if (cal == level) {
            ans = root;
            return ans;
        }
        if (ans == null)
            ans = Traverse(root.right, level, cal + 1);
        if (ans == null)
            ans = Traverse(root.left, level, cal + 1);
        return ans;
    }

    public static List<Integer> rightSideView(TreeNode root) {
        int n = CalLevel(root);
        List<Integer> ans = new ArrayList<>();
        if (root == null)
            return ans;
        for (int i = 0; i < n; i++) {
            ans.add(Traverse(root, i, 0).val);
        }
        return ans;
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
        System.out.println(rightSideView(root));
    }
}
