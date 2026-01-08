#include <iostream>

using namespace std;

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Function to reverse the linked list recursively
Node* reverseList(Node* head) {
    // Base case: if the list is empty or has only one node, return it
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursively reverse the rest of the list
    Node* restReversed = reverseList(head->next);

    // Change the next pointer of the current node
    head->next->next = head;
    head->next = nullptr;

    return restReversed;
}

int main() {
    // Create a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    // Clean up the memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
