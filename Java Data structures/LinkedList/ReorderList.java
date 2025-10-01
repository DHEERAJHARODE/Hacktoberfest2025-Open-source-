class Node {
    int val;
    Node next;

    public Node(int val) {
        this.val = val;
    }
}

public class ReorderList {
    public static ListNode reverseLL(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode prev = null;
        ListNode curr = head;
        ListNode newNode = null;
        while (curr != null) {
            newNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }

    public static void reorderList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        fast = slow.next;
        slow.next = null;
        fast = reverseLL(fast);
        ListNode t1 = head;
        ListNode t2 = fast;
        while (t1 != null && t2 != null) {
            ListNode newNode1 = t1.next;
            t1.next = t2;
            t1 = newNode1;
            ListNode newNode2 = t2.next;
            t2.next = t1;
            t2 = newNode2;
        }
    }

    public static void display(ListNode head) {
        if (head == null)
            return;
        System.out.print(head.val + " ");
        display(head.next);
    }

    public static void main(String[] args) {
        ListNode a = new ListNode(1);
        ListNode b = new ListNode(2);
        ListNode c = new ListNode(3);
        ListNode d = new ListNode(4);
        ListNode e = new ListNode(5);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        reorderList(a);
        display(a);
    }
}
