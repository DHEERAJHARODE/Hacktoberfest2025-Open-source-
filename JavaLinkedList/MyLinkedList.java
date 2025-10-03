// File: MyLinkedList.java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class MyLinkedList {
    Node head;

    public void addLast(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
    }

    public void addAtPosition(int data, int position) {
        Node newNode = new Node(data);
        if (position == 0) {
            newNode.next = head;
            head = newNode;
            return;
        }
        Node temp = head;
        for (int i = 0; i < position - 1 && temp != null; i++) temp = temp.next;
        if (temp == null) {
            System.out.println("Position out of bounds.");
            return;
        }
        newNode.next = temp.next;
        temp.next = newNode;
    }

    public void delete(int data) {
        if (head == null) return;
        if (head.data == data) {
            head = head.next;
            return;
        }
        Node temp = head;
        while (temp.next != null && temp.next.data != data) temp = temp.next;
        if (temp.next == null) {
            System.out.println("Element not found.");
            return;
        }
        temp.next = temp.next.next;
    }

    public void findMiddle() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        Node slow = head;
        Node fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        System.out.println("Middle element: " + slow.data);
    }

    public void reverse() {
        Node prev = null, current = head, next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    public void merge(MyLinkedList otherList) {
        if (head == null) {
            head = otherList.head;
            return;
        }
        Node temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = otherList.head;
    }

    public void display() {
        Node temp = head;
        if (temp == null) {
            System.out.println("List is empty.");
            return;
        }
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        MyLinkedList list1 = new MyLinkedList();
        list1.addLast(1);
        list1.addLast(2);
        list1.addLast(3);
        list1.display(); // 1 -> 2 -> 3 -> null

        list1.addAtPosition(4, 1);
        list1.display(); // 1 -> 4 -> 2 -> 3 -> null

        list1.delete(2);
        list1.display(); // 1 -> 4 -> 3 -> null

        list1.findMiddle(); // Middle element: 4

        list1.reverse();
        list1.display(); // 3 -> 4 -> 1 -> null

        MyLinkedList list2 = new MyLinkedList();
        list2.addLast(5);
        list2.addLast(6);

        list1.merge(list2);
        list1.display(); // 3 -> 4 -> 1 -> 5 -> 6 -> null
    }
}
