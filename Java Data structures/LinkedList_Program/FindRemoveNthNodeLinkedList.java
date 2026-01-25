public class FindRemoveNthNodeLinkedList {
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
    //delete the n th element fron end
    public void findandRemoveNthIndex(int n){
        int sz=0;
       
        Node temp= head;
        while (temp != null) {
            temp= temp.next;
            sz++;
        }

        if (n == sz) {
            head= head.next;
            return ;
        }
        // sz-n
        int i=1;
        int itoEnd= sz-n;
        Node prev= head;
        while (i < itoEnd) {
            prev= prev.next;
            i++;
        }
        prev.next= prev.next.next;
    }
    public static void main(String[] args) {
        FindRemoveNthNodeLinkedList ll= new FindRemoveNthNodeLinkedList();
        ll.addLast(1);
        ll.addLast(2);
        ll.addLast(3);
        ll.addLast(4);
        ll.addLast(5);
        ll.print();
        ll.findandRemoveNthIndex(2);
        ll.print();
    }
    
}
