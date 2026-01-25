public class LinedList {

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

    public void addFirst(int data){
        Node newNode= new Node(data);
        size++;
        if (head == null) {
            head = tail = newNode;
            return;
        }
        newNode.next= head;
        head= newNode;
    }

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

    public void addMiddle(int idx, int data){
        if (idx == 0) {
            addFirst(data);
            return;
        }
        Node newNode= new Node(data);
        size++;
        Node temp=head;
        int i=0;

        while (i < idx-1) {
            temp=temp.next;
            i++;
        }
        newNode.next=temp.next;
        temp.next=newNode;
    }
    public int removeFirst(){
        if (size == 0) {
            System.out.println("List is empty");
            return Integer.MIN_VALUE;
        }else if (size == 1) {
            int val= head.data;
            head = tail = null;
            size=0;
            return val;
        }
        int val= head.data;
        head= head.next;
        size--;
        return val;
    }
    public int removeLast(){
        if (size ==0) {
            System.out.println("List is empty");
            return Integer.MIN_VALUE;
        }else if (size == 1) {
            int val= head.data;
            head= tail= null;
            size=0;
            return val;
        }
        Node prev= head;
        for(int i=0; i<size-2; i++){
            prev=prev.next;
        }
        int val= tail.data;//prev.next.data;
        prev.next=null;
        tail= prev;
        size--;
        return val;
    }

    public int iterSearch(int key){
        Node temp=head;
        int i=0;

        while (temp != null) {
            if (temp.data == key) {
                return i;
            }
            temp=temp.next;
            i++;
        }
        return -1;
    }
    public int helper(Node head, int key){
        if (head == null) {
            return -1;
        }
        if (head.data == key) {
            return 0;
        }
        int idx= helper(head.next, key);
        if (idx == -1) {
            return -1;
        }
        return idx+1;

    }
    public int recursionSer(int key){
        return helper(head, key);
    }

    public void reverse(){
        Node prve= null;
        Node curr= tail = head;
        Node next;

        while (curr != null) {
            next= curr.next;
            curr.next=prve;
            prve=curr;
            curr= next;
        }
        head = prve;
    }
    public static void main(String[] args) {
        LinedList ll= new LinedList();
        ll.addFirst(2);
        ll.addFirst(1);
        ll.addLast(3);
        ll.addLast(4);
        ll.addLast(5);
        ll.addMiddle(2, 9);
        ll.print();
        System.out.println(ll.size);
        ll.removeFirst();
        ll.print();
        ll.removeLast();
        ll.print();
        System.out.println(ll.iterSearch(3));
        System.out.println(ll.iterSearch(10));
        System.out.println(ll.recursionSer(4));
        ll.reverse();
        ll.print();
    }
    
}
