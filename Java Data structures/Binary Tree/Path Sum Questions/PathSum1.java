class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class PathSum1 {// this algorithm calculates whether a root to leaf path sum is equals to target
                       // or not...............
    private static boolean Sum(TreeNode root, int sum, int target) {
        if (root == null)
            return false;
        sum += root.val;
        if (root.left == null && root.right == null) {
            return sum == target;
        }
        return Sum(root.left, sum, target) || Sum(root.right, sum, target);
    }

    public static boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)
            return false;
        return Sum(root, 0, targetSum);
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
        System.out.println(hasPathSum(root, 7));
    }
}