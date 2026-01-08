class Node{
    int data;
    Node next;
    Node(int data){
        this.data = data;
        next = null;
    }
    Node(){
        next = null;
    }
}
public class MiddleOfLinkedList{

    public static Node insertEnd(Node head, int data){
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
        }else{
            Node temp = head;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = newNode;
        }
        return head;
    }

    public static void display(Node head){
        if(head == null){
            System.out.println("LinkedList is Empty");
        }
        Node temp = head;
        while(temp != null){
            System.out.println(temp.data);
            temp = temp.next;
        }
    }


    public static Node MiddleNode(Node head){
        if(head == null){
            System.out.println("Empty Linkedlist");
            return head;
        }
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }


    public static void main(String[] args) {
        Node head = null;
        head = MiddleOfLinkedList.insertEnd(head, 10);
        head = MiddleOfLinkedList.insertEnd(head, 20);
        head = MiddleOfLinkedList.insertEnd(head, 30);
        head = MiddleOfLinkedList.insertEnd(head, 40);
        head = MiddleOfLinkedList.insertEnd(head, 50);
        MiddleOfLinkedList.display(head);
        Node Middle = MiddleOfLinkedList.MiddleNode(head);
        System.out.println("Middle of LinkedList is : "+ Middle.data);
    }
}