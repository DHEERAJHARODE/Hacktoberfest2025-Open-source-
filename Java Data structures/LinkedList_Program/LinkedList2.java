public class LinkedList2 {

    class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
            this.next=null;
        }

    }
    public static Node head;
    public static Node tail;
    public void addFirst(int data){
        Node newNode= new Node(data);
        if (head== null) {
            head= tail= newNode;
            return;
        }
        newNode.next=head;
        head= newNode;

    }
    public void print(){
        Node temp= head;
        if (head == null) {
            System.out.print("list is empty");
            return;

        }
        while (temp != null) {
            System.out.print(temp.data+"->");
            temp= temp.next;
        }
        System.out.println("null");
    }
    
    public static void main(String[] args) {
        LinkedList2 ll=new LinkedList2();

        ll.addFirst(5);
        ll.addFirst(4);
        ll.addFirst(3);
        ll.addFirst(2);
        ll.addFirst(1);
        ll.print();

    }
}
