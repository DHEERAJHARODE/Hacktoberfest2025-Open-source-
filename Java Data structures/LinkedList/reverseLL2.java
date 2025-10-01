class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode reverseLL(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode newNode = head.next;
        ListNode smallans = reverseLL(newNode);
        newNode.next = head;
        head.next = null;
        return smallans;
    }

    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head.next == null)
            return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode t1 = dummy;
        int i = 1;
        while (i < left) {
            t1 = t1.next;
            i++;
        }
        ListNode t2 = t1.next;
        i = left;
        while (i < right) {
            t2 = t2.next;
            i++;
        }
        ListNode r = t2.next;
        t2.next = null;
        ListNode l = t1.next;
        t1.next = null;
        l = reverseLL(l);
        ListNode temp = l;
        while (temp != null && temp.next != null) {
            temp = temp.next;
        }
        if (temp != null)
            temp.next = r;
        t1.next = l;
        return dummy.next;
    }
}

public class reverseLL2 {
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
        Solution s1 = new Solution();
        int left = 2;
        int right = 4;
        ListNode ans = s1.reverseBetween(a, left, right);
        display(ans);
    }
}
