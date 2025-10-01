class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class invertTree {
    public static void display(TreeNode root) {// pre-order traversal...................
        if (root == null)
            return;
        System.out.print(root.val + " ");
        display(root.left);
        display(root.right);
    }

    public static TreeNode invertTreekaro(TreeNode root) {
        if (root == null)
            return root;
        invertTreekaro(root.left);
        invertTreekaro(root.right);
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        return root;
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
        display(root);
        System.out.println();
        invertTreekaro(root);
        System.out.println("Inverted form is : ");
        display(root);// 1,3,7,6,2,5,4 expected..........
    }
}
