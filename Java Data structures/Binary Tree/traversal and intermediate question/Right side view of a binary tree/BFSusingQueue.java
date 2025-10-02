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

public class BFSusingQueue {
    private static void Traverse(TreeNode root, List<Integer> ans) {
        Queue<pair> q = new LinkedList<>();
        q.add(new pair(root, 0));
        int prevlvl = 0;
        pair x = null;
        ans.add(root.val);
        while (!q.isEmpty()) {
            x = q.remove();
            if (x.level != prevlvl) {
                ans.add(x.node.val);
                prevlvl = x.level;
            }
            if (x.node.right != null)
                q.add(new pair(x.node.right, prevlvl + 1));
            if (x.node.left != null)
                q.add(new pair(x.node.left, prevlvl + 1));
        }
    }

    public static List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null)
            return ans;
        Traverse(root, ans);
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
