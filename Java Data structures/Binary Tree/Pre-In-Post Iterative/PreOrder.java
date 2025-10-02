import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class PreOrder {
    public static void PreTraversal(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        st.push(root);// initially putting the root..........
        while (!st.empty()) {
            TreeNode x = st.pop();// poping the topmost element
            if (x.right != null)
                st.push(x.right);// putting right firstly because we can access topmost element................
            if (x.left != null)
                st.push(x.left);// then putting left..........(cause we want to do pre order.......)
            System.out.print(x.val + " ");// at last we would print the poped value.............
        }
        System.out.println();
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
        PreTraversal(root);
    }
}