import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
    }
}

class pair {
    Node node;
    int level;

    pair(Node node, int level) {
        this.node = node;
        this.level = level;
    }
}

class Solution {
    static ArrayList<Integer> topView(Node root) {
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        Queue<pair> q = new LinkedList<>();
        q.add(new pair(root, 0));
        while (!q.isEmpty()) {
            pair x = q.remove();
            if (x.node.left != null)
                q.add(new pair(x.node.left, x.level - 1));
            if (x.node.right != null)
                q.add(new pair(x.node.right, x.level + 1));
            if (!mp.containsKey(x.level)) {
                mp.put(x.level, x.node.data);
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (var elem : mp.keySet()) {
            ans.add(mp.get(elem));
        }
        return ans;
    }

    static void printTree(Node root) {
        if (root == null)
            return;
        System.out.print(root.data + " ");
        printTree(root.left);
        printTree(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node b = new Node(2);
        Node c = new Node(3);
        Node d = new Node(4);
        Node e = new Node(5);
        Node f = new Node(6);
        Node g = new Node(7);
        root.left = b;
        root.right = c;
        b.left = d;
        b.right = e;
        c.left = f;
        c.right = g;
        System.out.println(topView(root));
    }
}