class LinkedList {

  // create an object of Node class
  // represent the head of the linked list
  Node head;

  // static inner class
  static class Node {
    int value;

    // connect each node to next node
    Node next;

    Node(int d) {
      value = d;
      next = null;
    }
  }

  public static void main(String[] args) {

    // create an object of LinkedList
    LinkedList linkedList = new LinkedList();

    // assign values to each linked list node
    linkedList.head = new Node(1);
    Node second = new Node(2);
    Node third = new Node(3);

    // connect each node of linked list to next node
    linkedList.head.next = second;
    second.next = third;

    // printing node-value
    System.out.print("LinkedList: ");
    while (linkedList.head != null) {
      System.out.print(linkedList.head.value + " ");
      linkedList.head = linkedList.head.next;
    }
  }
}
