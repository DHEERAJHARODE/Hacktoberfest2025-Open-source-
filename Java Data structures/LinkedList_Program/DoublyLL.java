public class DoublyLL {

    public static class Node{

        int data;
        Node next;
        Node prve;

        public Node(int data){
            this.data= data;
            this.next= null;
            this.prve= null;
        }
    }

    public static Node head;
    public static Node tail;
    public static int size;

    public void addFirst(int data){
        Node newNode= new Node(data);
        size++;
        if(head == null) {
            head= tail = newNode;
            return;
        }
        newNode.next = head;
        head.prve= newNode;
        head = newNode;
    }

    public void addLast(int data){
        Node newNode= new Node(data);
        size++;
        if (head == null) {
            head= tail= newNode;
            return;
        }
        tail.next= newNode;
        newNode.prve= tail;
        tail= newNode;
    }

    public int removeFirst(){
        if (size ==0) {
            System.out.println("list is empty");
            return Integer.MAX_VALUE;
        }else if (size == 1) {
            int val= head.data;
            head = tail = null;
            size=0;
            return val;
        }
        int val= head.data;
        head=head.next;
        head.prve= null;
        size--;
        return val;
    }

    public int removeLast(){
        if (size ==0) {
            System.out.println("list is empty");
            return Integer.MAX_VALUE;
        }else if (size == 1) {
            int val= head.data;
            head = tail = null;
            size=0;
            return val;
        }
        int val= tail.data;
        tail.prve.next= null;
        return val;

    }

    public void print(){
        Node temp= head;
        if (head == null) {
            System.out.println("list is empty");
            return;
        }
        while (temp != null) {
            System.out.print(temp.data+"<->");
            temp=temp.next;
        }
        System.out.println("null");
    }
   
    public static void reveseDll(){
        Node curr= head;
        Node prve= null;
        Node next;

        while (curr != null) {
            next= curr.next;
            curr.next= prve;
            curr.prve= next;// this line for doubly linked list
            prve= curr;
            curr= next;
        }
        head = prve;
    }

    public static void main(String[] args) {
        DoublyLL dll= new DoublyLL();

        dll.addLast(1);
        dll.addLast(2);
        dll.addLast(3);
        dll.addLast(4);
        dll.addLast(5);
        dll.print();

        // dll.removeFirst();
        dll.removeFirst();
        dll.print();

        dll.reveseDll();
        dll.print();
    }
    
}
