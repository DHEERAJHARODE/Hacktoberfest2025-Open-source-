class Node {
    int val;
    Node next;

    public Node(int val) {
        this.val = val;
    }
}

public class SwapNodesInPair {
    public static Node swapPairs1(Node head) {// recursive approach............
        if (head == null || head.next == null)
            return head;
        Node newNode1 = head.next;// store the addresses of next and next.next nodes..........
        Node newNode2 = head.next.next;
        Node smallans = swapPairs1(newNode2);// call recursion..............
        newNode1.next = head;// connect second node to first node........
        head.next = smallans;// connect first node to forward node.......
        return newNode1;// return second Node (because it is answer head now..........)
    }

    public static Node swapPairs(Node head) {// iterative approach...........
        if (head == null || head.next == null)
            return head;
        Node t1 = head;
        Node t2 = head.next;
        Node ans = t2;// point to second node because its gonna be head at the answer time...........
        while (t2.next != null && t2.next.next != null) {
            Node newNode1 = t2.next;// store the addresses of next and next.next nodes..............
            Node newNode2 = t2.next.next;
            t2.next = t1;// connect t2 to t1;
            t1.next = newNode2;// connect t1 to newNode2 (t2.next.next address)..........
            t1 = newNode1;// make t1 as (t2.next address)..........
            t2 = newNode2;// make t2 as (t2.next.next address)..........
        }
        if (t2.next == null) {// if list is even...........
            t2.next = t1;
            t1.next = null;
            return ans;
        } else {// if list is odd............
            Node newNode1 = t2.next;
            t2.next = t1;
            t1.next = newNode1;
            return ans;
        }
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
        a.next = b;
        b.next = c;
        c.next = d;
        Node ans = swapPairs(a);
        display(ans);
    }
}
