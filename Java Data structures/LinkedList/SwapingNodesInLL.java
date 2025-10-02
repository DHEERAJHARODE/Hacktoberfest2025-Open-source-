class Node {
    int val;
    Node next;

    public Node(int val) {
        this.val = val;
    }
}

public class SwapingNodesInLL {
    public static void display(Node head) {
        if (head == null) {
            System.out.println();
            return;
        }
        System.out.print(head.val + " ");
        display(head.next);
    }

    // public static Node swapNodes(Node head, int k) {// brute force approach to
    // swap nodes in a linkedlist...
    // Node slow = head;
    // Node fast = head;
    // int size = 0;
    // while (slow != null) {// we calculate the size of the linkedlist
    // size++;
    // slow = slow.next;
    // }
    // slow = head;
    // if (size + 1 - k == k) {// if nth node from the start and nth node from the
    // end is same then simply
    // // return....
    // return head;
    // }
    // size = size + 1 - k;
    // int i = 1;
    // while (i < size) {// put a pointer on nth node from the last...
    // fast = fast.next;
    // i++;
    // }
    // i = 1;
    // while (i < k) {// put a pointer on nth node from the start...
    // slow = slow.next;
    // i++;
    // }
    // int temp = fast.val;// swap the values.....
    // fast.val = slow.val;
    // slow.val = temp;
    // return head;
    // }
    public static Node swapNodes(Node head, int k) {// efficient approach.......
        Node slow = head;
        Node fast = head;
        int i = 1;
        while (i <= k) {// first of all move fast pointer to k no. of times....
            fast = fast.next;
            i++;
        }
        while (fast != null) {// move both node simultaneously till the fast reaches the null......
            slow = slow.next;
            fast = fast.next;
        } // now our slow will point to nth node from last........
        fast = head;// initialize fast as head (reuse).....
        i = 1;
        while (i < k) {// move k-1 times to reach nth node from start......
            fast = fast.next;
            i++;
        }
        if (slow == fast)// if nth node from start and nth node from last is same...........
            return head;
        int temp = fast.val;// swap........
        fast.val = slow.val;
        slow.val = temp;
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
        int k = 2;
        Node anshead = swapNodes(a, k);
        display(anshead);
    }
}
