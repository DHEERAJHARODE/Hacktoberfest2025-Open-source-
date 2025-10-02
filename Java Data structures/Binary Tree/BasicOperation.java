class Node {
    int val;
    Node left;
    Node right;

    Node(int val) {
        this.val = val;
    }
}

public class BasicOperation {
    public static int SumNode(Node root) {
        if (root == null)
            return 0;
        return SumNode(root.left) + SumNode(root.right) + root.val;
    }

    public static void display(Node root) {// pre-order traversal...................
        if (root == null)
            return;
        System.out.print(root.val + " ");
        display(root.left);
        display(root.right);
    }

    public static int ProductNode(Node root) {
        if (root == null || root.val == 0)
            return 1;
        return ProductNode(root.left) * ProductNode(root.right) * root.val;
    }

    public static int MaxValueNode(Node root) {
        if (root == null) {
            return 0;
        }
        return Math.max(root.val, Math.max(MaxValueNode(root.left), MaxValueNode(root.right)));// or
                                                                                               // Manual................
        // int l = MaxValueNode(root.left);
        // int r = MaxValueNode(root.right);
        // if (l > root.val && l > r)
        // return l;
        // else if (r > root.val)
        // return r;
        // else
        // return root.val;
    }

    public static int MinValueNode(Node root) {
        if (root == null) {
            return 0;
        }
        return Math.min(root.val, Math.min(MinValueNode(root.left), MinValueNode(root.right)));
    }

    public static int SizeOfTree(Node root) {
        if (root == null)
            return 0;
        return 1 + SizeOfTree(root.left) + SizeOfTree(root.right);
    }

    public static int LevelsOfTree(Node root) {
        if (root == null) {
            return 0;
        }
        return 1 + Math.max(LevelsOfTree(root.left), LevelsOfTree(root.right));
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node b = new Node(4);
        Node c = new Node(-5);
        Node d = new Node(8);
        Node e = new Node(3);
        Node f = new Node(10);
        Node g = new Node(2);
        root.left = b;
        root.right = c;
        b.left = d;
        b.right = e;
        c.left = f;
        c.right = g;
        display(root);
        System.out.println();
        int sum = SumNode(root);
        System.out.println("The sum of the Nodes is : " + sum);
        int ProductNode = ProductNode(root);
        System.out.println("The product of the Nodes are : " + ProductNode);
        int max = MaxValueNode(root);
        System.out.println("The max value Node is : " + max);
        int min = MinValueNode(root);
        System.out.println("The min value of the Node is : " + min);
        int size = SizeOfTree(root);
        System.out.println("The size of the tree is : " + size);
        int level = LevelsOfTree(root);
        System.out.println("There are " + level + " levels of the tree");
    }
}