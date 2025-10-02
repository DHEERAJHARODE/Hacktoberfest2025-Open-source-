class Node {
    int val;
    Node next;

    public Node(int val) {
        this.val = val;
    }
}

public class Merge {
    public static Node mergeTwoLists(Node list1, Node list2) {// inplace efficient approach to merge two sorted
                                                              // list............
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        Node t1 = list1;
        Node t2 = list2;
        while (t1 != null && t2 != null) {
            if (t1.next != null && t1.next.val <= t2.val) {
                t1 = t1.next;
            } else if (t2.next != null && t2.next.val < t1.val) {
                t2 = t2.next;
            } else if (t1.val <= t2.val) {
                Node newNode = t1.next;
                t1.next = t2;
                t1 = newNode;
            } else {
                Node newNode = t2.next;
                t2.next = t1;
                t2 = newNode;
            }
        }
        if (list1.val <= list2.val) {
            return list1;
        } else {
            return list2;
        }
    }

    public static void display(Node head) {
        if (head == null)
            return;
        System.out.print(head.val + " ");
        display(head.next);
    }

    public static void main(String[] args) {
        Node a = new Node(0);
        Node b = new Node(6);
        Node c = new Node(9);
        a.next = b;
        b.next = c;
        Node d = new Node(1);
        Node e = new Node(2);
        Node f = new Node(3);
        Node g = new Node(4);
        d.next = e;
        e.next = f;
        f.next = g;
        Node ans = mergeTwoLists(a, d);
        display(ans);
    }
}
