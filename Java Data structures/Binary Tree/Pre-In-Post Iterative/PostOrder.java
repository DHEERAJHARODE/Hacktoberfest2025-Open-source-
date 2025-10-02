import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class PostOrder {// in this algorithm firstly we stored the reverse pre order the then reversed
                        // it............
    public static void PostTraversal(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        st.push(root);// initially put the root......
        while (!st.empty()) {
            TreeNode x = st.pop();// poped the first element...........
            if (x.left != null)
                st.push(x.left);// pushed left (if present) firstly.............
            if (x.right != null)
                st.push(x.right);// pushed right (if present) secondly...........
            arr.add(x.val);
        }
        for (var i : arr.reversed())// print the reversed form....................
            System.out.print(i + " ");
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
        PostTraversal(root);
    }
}
