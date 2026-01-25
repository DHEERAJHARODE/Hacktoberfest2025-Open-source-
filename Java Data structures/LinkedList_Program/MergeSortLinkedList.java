public class MergeSortLinkedList {

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
    
    private Node getMid(Node head){
        Node slow= head;
        Node fast= head.next;

        while (fast != null && fast.next != null) {
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }

    private Node merge(Node head1, Node head2){

        Node mergeLL= new Node(-1);
        Node temp= mergeLL;

        while (head1 != null && head2 != null) {
            if (head1.data <= head2.data) {
                temp.next= head1;
                head1=head1.next;
                temp=temp.next;
            }else{
                temp.next=head2;
                head2=head2.next;
                temp=temp.next;
            }

            while (head1 != null) {
                temp.next= head1;
                head1=head1.next;
                temp=temp.next;
            }

            while (head2 != null) {
                temp.next=head2;
                head2=head2.next;
                temp=temp.next;
            }
        }
            return mergeLL.next;
    }

    public Node mergeSort(Node head){
        if (head == null || head.next == null) {
            return head;
        }

        Node midNode=getMid(head);
        Node rightHead= midNode.next;
        midNode.next=null;


        Node newLeft= mergeSort(head);
        Node newRight= mergeSort(rightHead);

        return merge(newLeft, newRight);

    }
    public void addFirst(int data){
        Node newNode= new Node(data);
        if (head == null) {
            head= tail=newNode;
            return;
        }
        newNode.next= head;
        head= newNode;
    }

    public void printL(){
        Node temp= head;
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        

        while (temp != null) {
            System.out.print(temp.data+ "->");
            temp=temp.next;
        }
        System.out.println("null");

    }
    public static void main(String[] args) {
        MergeSortLinkedList ll= new MergeSortLinkedList();
        ll.addFirst(1);
        ll.addFirst(2);
        ll.addFirst(3);
        ll.addFirst(4);
        ll.addFirst(5);

        ll.printL();

        ll.head=ll.mergeSort(ll.head);
        

        ll.printL();

    }
    
}
