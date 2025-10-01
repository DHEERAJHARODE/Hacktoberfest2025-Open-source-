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

class Morris {
    public static List<Integer> inorderTraversal(TreeNode root) {
        TreeNode curr = root;
        List<Integer> ans = new ArrayList<>();
        while (curr != null) {
            if (curr.left != null) {
                TreeNode pred = curr.left;
                while (pred.right != null && pred.right != curr)// finding predecessor...............
                    pred = pred.right;
                if (pred.right == null) {// if predecessor found then link its right to the current node..........ans
                                         // shift current to left.......
                    pred.right = curr;
                    curr = curr.left;
                } else {// if cycle found(i.e. previous fake linking) then store/print the answer and
                        // unlink the fake linking and shift current to the right...
                    pred.right = null;
                    ans.add(curr.val);
                    curr = curr.right;
                }
            } else {// if current node's left is null then store/print answer and shift current node
                    // to the right..................
                ans.add(curr.val);
                curr = curr.right;
            }
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
        System.out.println(Morris.inorderTraversal(root));
    }
}