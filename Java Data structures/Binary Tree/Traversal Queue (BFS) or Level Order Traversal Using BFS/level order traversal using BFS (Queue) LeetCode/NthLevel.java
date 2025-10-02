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

class pair {
    TreeNode node;
    int level;

    pair(TreeNode node, int level) {
        this.node = node;
        this.level = level;
    }
}

public class NthLevel {
    public static int Nth(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(Nth(root.left), Nth(root.right));
    }

    public static void printNthLevel(TreeNode root) {// can print entire as well as nth level.................efficient
                                                     // approach...........
        Queue<pair> q = new LinkedList<>();
        int prevlvl = 0;
        q.add(new pair(root, prevlvl));
        while (!q.isEmpty()) {
            pair x = q.remove();
            if (x.level != prevlvl) {
                prevlvl = x.level;
                System.out.println();
            }
            if (x.node.left != null)
                q.add(new pair(x.node.left, prevlvl + 1));
            if (x.node.right != null)
                q.add(new pair(x.node.right, prevlvl + 1));
            System.out.print(x.node.val + " ");
        }
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
        g.left = new TreeNode(8);
        printNthLevel(root);
    }
}