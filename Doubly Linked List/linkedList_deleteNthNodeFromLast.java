import java.util.LinkedList;
import java.util.Scanner;

public class linkedList_deleteNthNodeFromLast {
    public int size;
    linkedList_deleteNthNodeFromLast(){
        this.size = 0;
    }
    Node head = null;

    class Node{
        int value;
        Node next;

        Node(int value){
            this.value = value;
            this.next = null;
            size++;
        }
    }

    public void addElement(int value){
        if(head == null){
            Node newnode = new Node(value);
            head = newnode;
            return;
        }
        Node newnode = new Node(value);
        newnode.next = head;
        head = newnode;

    }

    public void deleteElement(){
        if(head == null || head.next == null){
            head = null;
            size = 0;
        }

        head = head.next;
        size--;
    }

    public void deleteList(int lastIndex){
        // System.out.println(this.size);
        int fromFrontPrev = this.size - lastIndex;
        Node prevIndex = head;
        int i=1;
        while(i<fromFrontPrev){
            prevIndex = prevIndex.next;
            i++;
        }

        prevIndex.next = prevIndex.next.next;

    }

    public void printList(){
        for(Node currentNode = head; currentNode!=null; currentNode = currentNode.next){
            System.out.print(currentNode.value+" -> ");
        }
        System.out.println("NULL");
    }
    public static void main(String[] args) {
        linkedList_deleteNthNodeFromLast list = new linkedList_deleteNthNodeFromLast();
        list.addElement(1);
        list.addElement(2);
        list.addElement(3);
        list.addElement(4);
        list.addElement(5);
        System.out.println(list.size);
        System.out.println("enter the node u want to delete from last");
        Scanner sc = new Scanner(System.in);
        int lastNode = sc.nextInt();
        list.deleteList(lastNode);
        list.printList();
        
    }
}
