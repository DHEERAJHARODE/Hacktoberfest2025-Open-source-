import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class DFS {
    private static int CalLevel(TreeNode root) {// function to calculate the level...................
        if (root == null)
            return 0;
        return 1 + Math.max(CalLevel(root.left), CalLevel(root.right));
    }

    private static void preTraverse(TreeNode root, int level, List<Integer> ans) {// Normal pre-order
        // traversal..................
        if (root == null)
            return;
        ans.set(level, root.val);// setting answer while performing pre-order traversal........................
        preTraverse(root.left, level + 1, ans);
        preTraverse(root.right, level + 1, ans);
    }

    public static List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null)
            return ans;
        int n = CalLevel(root);
        for (int i = 0; i < n; i++) {// initially putting 0 to the nth length of the array...............
            ans.add(0);
        }
        preTraverse(root, 0, ans);// calling the function....................
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