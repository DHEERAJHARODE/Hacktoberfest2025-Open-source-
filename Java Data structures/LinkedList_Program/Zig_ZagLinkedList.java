public class Zig_ZagLinkedList {


    public static class Node{

        int data;
        Node next;
        
        Node (int data){
            this.data=data;
            this.next=null;
        }
    }
    public static Node head;
    public static Node tail;

    public void addLast(int data){
        Node newNode= new Node(data);
        if (head == null) {
            head= tail = newNode;
            return;
        }

        tail.next= newNode;
        tail= newNode;
    }

    public void print(){
        Node temp= head;
        if (head== null) {
            System.out.println("list is empty");
            return;
        }
        while (temp != null) {
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }

    //Zig- zag linked List
    public void zihzagLL(Node head){
        // find mid
        Node slow= head;
        Node fast= head.next;

        while (fast != null && fast.next != null) {
            slow= slow.next;
            fast= fast.next.next;
        }

        Node mid= slow;

        // reverse half ll Node
        Node curr= mid.next;
        mid.next= null;
        Node prve= null;
        Node next;

        while (curr != null) {
            next= curr.next;
            curr.next= prve;
            prve= curr;
            curr= next;
        }

        Node right=prve;
        Node left= head;
        Node nextL;
        Node nextR;

        //attach zig-zag list 
        //list is: 1->2->3->4->
        // it became:= 1->5->2->4->3

        while (left != null && right != null) {
            nextL= left.next;
            left.next= right;
            nextR= right.next;
            right.next= nextL;

            right= nextR;
            left= nextL;
        }



    }
    public static void main(String[] args) {
        Zig_ZagLinkedList ll= new Zig_ZagLinkedList();
        ll.addLast(1);
        ll.addLast(2);
        ll.addLast(3);
        ll.addLast(4);
        ll.addLast(5);
        ll.print();
        ll.zihzagLL(head);
        ll.print();

    }
    
}
