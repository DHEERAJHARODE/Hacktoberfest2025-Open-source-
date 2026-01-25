public class LinkedListIsPalindrom {
    public static class Node{

        int data;
        Node next;

        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    public static Node head;
    public static Node tail;
    public static int size;
    public void addLast(int data){
        Node newNode= new Node(data);
        size++;
        if (head == null) {
            head= tail = newNode;
            return;
        }
        tail.next= newNode;
        tail= newNode;
    }
    public void print(){
        if (head == null) {
            System.out.println("List is empty");
        }
        Node temp= head;
        while ( temp != null) {
            System.out.print(temp.data+ "->");
            temp= temp.next;
        }
        System.out.println("null");
    }

    public Node findMid(Node head){ // helper function
        Node slow= head;
        Node fast= head;

        while (fast != null && fast.next != null) {
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public boolean checkPalindrom(){
        if (head == null || head.next== null) {
            return true;
        }

        // find mid
        Node midNode= findMid(head);

        // reverse the 2nd half
        Node prev= null;
        Node curr= midNode;
        Node next;

        while (curr != null) {
            next= curr.next;
            curr.next= prev;
            prev= curr;
            curr= next;
        }

        // check the right and left
        Node right=prev;
        Node left=head;
        while (right != null) {
            if (left.data != right.data) {
                return false;
            }
            left=left.next;
            right=right.next;
        }
        return true;

        
    }

    public static void main(String[] args) {
        LinkedListIsPalindrom ll=new LinkedListIsPalindrom();
        ll.addLast(1);
        ll.addLast(2);
        ll.addLast(2);
        ll.addLast(2);
        ll.addLast(1);
        ll.print();

        System.out.println(ll.checkPalindrom());
    }
    
}
