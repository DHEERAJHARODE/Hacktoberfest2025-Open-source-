class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class SymmetricTree {
    public static void display(TreeNode root) {// pre-order traversal...................
        if (root == null)
            return;
        System.out.print(root.val + " ");
        display(root.left);
        display(root.right);
    }

    public static TreeNode invertTreekaro(TreeNode root) {// inverts a tree..............
        if (root == null)
            return root;
        invertTreekaro(root.left);// invert left part of tree by recursion.........
        invertTreekaro(root.right);// invert right part of tree by recursion...........
        TreeNode temp = root.left;// swap the left and right TreeNodes...........
        root.left = root.right;
        root.right = temp;
        return root;// And return root...............
    }

    private static boolean CheckTree(TreeNode p, TreeNode q) {// checks whether two trees or subtrees are same or
                                                              // not.........
        if (p == null && q == null)
            return true;
        else if (p == null && q != null)
            return false;
        else if (p != null && q == null)
            return false;
        if (p.val == q.val) {// if p's value and q's value is equal then check other parts by
                             // recursion................
            return CheckTree(p.left, q.left) && CheckTree(p.right, q.right);// Only if both parts are equal then return
                                                                            // true else false.........
        } else
            return false;// else return false..................
    }

    public static boolean isSymmetric(TreeNode root) {// symmetric tree function.......................
        if (root == null)
            return true;
        TreeNode rightInverse = invertTreekaro(root.right);// invert the right of the root.......
        return CheckTree(root.left, rightInverse);// And check whether left part and right parts are same or
                                                  // not..........
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode b = new TreeNode(2);
        TreeNode c = new TreeNode(2);
        TreeNode d = new TreeNode(3);
        TreeNode e = new TreeNode(4);
        TreeNode f = new TreeNode(4);
        TreeNode g = new TreeNode(3);
        root.left = b;
        root.right = c;
        b.left = d;
        b.right = e;
        c.left = f;
        c.right = g;
        System.out.println("Is Symmetrical ? ");
        boolean isTreeSymmetrical = isSymmetric(root);
        System.out.println(isTreeSymmetrical);
    }
}
