class Node {
    int val;
    Node next;

    public Node(int val) {
        this.val = val;
    }
}

public class DetectCycle {
    public static Node detectCycle(Node head) {
        Node slow = head;
        Node fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                break;
        }
        if (fast == null || fast.next == null)// edge cases..........
            return null;
        Node temp = head;
        if (temp == slow)// edge cases.......
            return temp;
        while (slow != temp) {
            temp = temp.next;
            slow = slow.next;
        }
        return slow;
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
        e.next = b;// cycle....at 1 position..
        Node ans = detectCycle(a);
        System.out.println("Value of cycled node is " + ans.val);
    }
}
