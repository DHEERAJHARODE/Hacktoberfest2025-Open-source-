class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
    }
}

public class RotateList {// Reversing Brute force approach...............
    // public static Node reverseLL(Node head) {
    // if (head == null || head.next == null)
    // return head;
    // Node smallans = reverseLL(head.next);
    // head.next.next = head;
    // head.next = null;
    // return smallans;
    // }

    // public static Node rotateRight(Node head, int k) {
    // if (head == null || head.next == null)
    // return head;
    // Node t1 = head;
    // int size = 0;
    // while (t1 != null) {// to calculate size............
    // t1 = t1.next;
    // size++;
    // }
    // k = k % size;
    // int i = 1;
    // t1 = head;
    // while (i < size - k) {// to find the point from where the list to be
    // rotated...........
    // t1 = t1.next;
    // i++;
    // }
    // Node t2 = t1.next;
    // t1.next = null;// dividing list into two haves.......
    // head = reverseLL(head);// reversing the first part..............
    // t2 = reverseLL(t2);// reversing the second part...........
    // t1 = head;
    // while (t1.next != null) {// reaching the last node of the first part of the
    // list.............
    // t1 = t1.next;
    // }
    // t1.next = t2;// linking the last Node of first part to the second part of the
    // list..........
    // head = reverseLL(head);// reversing the whole list........................
    // return head;
    // }
    // efficient approach......................
    public static Node rotateRight(Node head, int k) {
        if (head == null || head.next == null) {
            return head;
        }

        Node oldTail = head;
        int length = 1;
        while (oldTail.next != null) {
            oldTail = oldTail.next;
            length++;
        }

        oldTail.next = head;
        Node newTail = head;
        for (int i = 0; i < length - k % length - 1; i++) {
            newTail = newTail.next;
        }

        Node newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }

    public static void display(Node head) {
        if (head == null) {
            System.out.println();
            return;
        }
        System.out.print(head.val + " ");
        display(head.next);
    }

    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(3);
        Node d = new Node(4);
        Node e = new Node(5);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        int k = 2;
        Node anshead = rotateRight(a, k);
        display(anshead);
    }
}
