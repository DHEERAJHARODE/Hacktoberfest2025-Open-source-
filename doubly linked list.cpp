#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

void insertFront(struct Node** head, int data) {
  struct Node* newNode = new Node;

  newNode->data = data;

  newNode->next = (*head);

  newNode->prev = NULL;

  if ((*head) != NULL)
    (*head)->prev = newNode;

  (*head) = newNode;
}

void insertAfter(struct Node* prev_node, int data) {
  if (prev_node == NULL) {
    cout << "previous node cannot be null";
    return;
  }

  struct Node* newNode = new Node;

  newNode->data = data;

  newNode->next = prev_node->next;

  prev_node->next = newNode;

  newNode->prev = prev_node;

  if (newNode->next != NULL)
    newNode->next->prev = newNode;
}

void insertEnd(struct Node** head, int data) {
  struct Node* newNode = new Node;

  newNode->data = data;

  newNode->next = NULL;

  struct Node* temp = *head;

  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }


  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;

  newNode->prev = temp;
}


void deleteNode(struct Node** head, struct Node* del_node) {
 
  if (*head == NULL || del_node == NULL)
    return;


  if (*head == del_node)
    *head = del_node->next;

  
  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;


  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;


  free(del_node);
}
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    cout << node->data << "->";
    last = node;
    node = node->next;
  }
  if (node == NULL)
    cout << "NULL\n";
}

int main() {

  struct Node* head = NULL;

  insertEnd(&head, 5);
  insertFront(&head, 1);
  insertFront(&head, 6);
  insertEnd(&head, 9);

 
  insertAfter(head, 11);

 
  insertAfter(head->next, 15);

  displayList(head);

  
  deleteNode(&head, head->next->next->next->next->next);

  displayList(head);
}
