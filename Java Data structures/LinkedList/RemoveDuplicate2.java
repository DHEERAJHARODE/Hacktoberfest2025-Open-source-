class Node {
    int val;
    Node next;

    public Node(int val) {
        this.val = val;
    }
}

public class RemoveDuplicate2 {
    public static Node deleteDuplicates(Node head) {
        if (head == null || head.next == null)// edge cases.....
            return head;
        int count = 1;
        if (head.val == head.next.val) {// to remove the initial duplicates................
            while (head != null && head.next != null && head.val == head.next.val) {
                while (head.next != null && head.val == head.next.val) {
                    head = head.next;
                }
                head = head.next;
            }
        }
        Node t1 = head;
        Node t2 = null;
        if (head != null)// edge cases...........
            t2 = head.next;
        while (t2 != null) {
            if ((t2.next == null || t2.val != t2.next.val) && count == 1) {// if there is unique (non-duplicate one)
                                                                           // element......
                t1.next = t2;
                t1 = t2;
                t2 = t2.next;
            } else if ((t2.next == null || t2.val != t2.next.val) && count > 1) {// if pointer reached the last
                                                                                 // duplicate element of duplicate
                                                                                 // series......
                t2 = t2.next;
                count = 1;
            } else {// if there are duplicates of current element.........
                t2 = t2.next;
                count++;
            }
        }
        if (t1 != null)// edge cases........
            t1.next = t2;
        return head;
    }

    public static void display(Node head) {
        if (head == null)
            return;
        System.out.print(head.val + " ");
        display(head.next);
    }

    public static void main(String[] args) {
        Node a = new Node(0);
        Node b = new Node(0);
        Node c = new Node(1);
        Node d = new Node(4);
        Node e = new Node(4);
        Node f = new Node(7);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        Node ans = deleteDuplicates(a);
        display(ans);
    }
}
