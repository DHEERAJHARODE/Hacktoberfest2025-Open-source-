// LinkedList.java
// Author: Akshat Sharma
// Description: Basic Singly Linked List implementation in Java.


public class LinkedList{
    Node head;

    static class Node{
        int data;
        Node next;

        Node(int d){
            data = d;
            next = null;
        }
    }

      public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Linkedlist list = new Linkedlist();
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.display();
    }

}
