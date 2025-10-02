class Node {
    int val;
    Node next;

    public Node(int val) {
        this.val = val;
    }
}

public class NthNodeFromEnd {
    public static void display(Node head) {
        if (head == null)
            return;
        System.out.print(head.val + " ");
        display(head.next);
    }

    public static Node removeNthFromEnd(Node head, int n) {// this one is efficient method for removing nth node from
                                                           // the end of the list.......
        Node slow = head;
        Node fast = head;
        int i = 1;
        while (i <= n) {// placing the fast after nth node......(this question require a little bit
                        // math)..........
            i++;
            fast = fast.next;
        }
        if (fast == null) {// edge case.........
            head = head.next;
            display(head);
            return head;
        }
        while (fast.next != null) {// forwarding slow and fast together.............until the fast.next !=
                                   // null...............
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;// deleting process..........
        display(head);
        return head;
    }

    public static void main(String[] args) {
        Node a = new Node(0);
        Node b = new Node(6);
        Node c = new Node(9);
        Node d = new Node(1);
        Node e = new Node(34);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        int kthNode = 2;
        removeNthFromEnd(a, 2);
    }
}