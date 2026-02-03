#include <iostream>
using namespace std;

class node {

public :
    int data;
    node * next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(node*& head, int data) {

    node* n = new node(data);
    n->next = head;
    head = n;

}

node* getTail(node* head) {

    node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    return tail;
}


void buildLinkedlist(node*& head, int data) {

    if (!head) {
        insertAtHead(head, data);
        return ;
    }

    node * n = new node(data);

    node * tail =   getTail(head);

    tail->next = n;

}

void printLinkedList(node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;

}


void copylinkedlist(node* head) {


    node* newhead = new node(head->data);
    head = head->next;

    node* temp = newhead;

    while (head) {
        node* c = new node(head->data);

        newhead->next = c;
        head = head->next;
        newhead = newhead->next;
    }

    printLinkedList(temp);

    buildLinkedlist(temp, 40);
    printLinkedList(temp);


}



int main() {

    node * head = NULL;

    buildLinkedlist(head, 10);
    buildLinkedlist(head, 20);
    buildLinkedlist(head, 30);

    printLinkedList(head);

    copylinkedlist(head);

    buildLinkedlist(head, 50);

    printLinkedList(head);

    copylinkedlist(head);



}
