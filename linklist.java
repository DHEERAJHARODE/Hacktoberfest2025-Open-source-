public class DoublyLinkedList { 
    
    class Node {
    // stores data 
    public int data;
    
    // pointer to the next node
    public Node next;
    
    // pointer to the previous node
    public Node prev;
}
  
    // To represent the head of a doubly linked list
    Node head = null;
    
    // To represent the tail of a doubly-linked list
    Node tail = null;
    
    public void addNodeFront(int val) {
    Node temp = new Node(val, head, null);
    
    if(head != null ) 
    {
        head.prev = temp;
    }
    
    head = temp;
    
    if(tail == null) 
    { 
        tail = temp;
    }
    
        System.out.println("New node added: " + val);
    }
    
    public void addNodeBack(int val) {      
    Node temp = new Node(val, null, tail);
    
    if(tail != null) 
    {
        tail.next = temp;
    }
    
    tail = temp;
    
    if(head == null) 
    { 
        head = temp;
    }
    
        System.out.println("New node added: " + val);
    }
    
    public int removeNodeFront() {
        
        Node temp = head;
    
        head = head.next;
        head.prev = null;
    
        System.out.println("deleted: " + temp.data);
        return temp.data;
    }
    
    public int removeNodeBack() {
        
        Node temp = tail;
    
        tail = tail.prev;
        tail.next = null;
    
        System.out.println("deleted: " + temp.data);
        return temp.data;
    }
    
    public void iterateForward(){
         
    Node temp = head;
        
    while(temp != null){
        System.out.println(temp.data);
        temp = temp.next;
    }
    }
    
    public void iterateBackward(){
         
    Node temp = tail;
    
    while(temp != null){
        System.out.println(temp.data);
            temp = temp.prev;
        }
    }
    
}
