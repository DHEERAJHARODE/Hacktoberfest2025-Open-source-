//Delete N nodes after M nodes of a linked list using C++ program


#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

//Create a new node
struct node* create_node(int x)
{
    struct node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

//Enter the node into the linked list
void push(node** head, int x)
{
    struct node* store = create_node(x);
    if (*head == NULL) {
        *head = store;
        return;
    }
    struct node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = store;
}

//Reverse the linked list
void delete_node(node* head, int m, int n)
{
    struct node* temp = head;
    int count = 1;
    while (1) {
        while (temp && count < m) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL) {
            return;
        }
        count = 1;
        struct node* store = temp;
        temp = temp->next;
        while (temp && count < n) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            return;
        }
        store->next = temp->next;
        temp = temp->next;
    }
}

//Print the list
void print(node* head)
{
    struct node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    struct node* l = NULL;
    push(&l, 1);
    push(&l, 2);
    push(&l, 3);
    push(&l, 4);
    push(&l, 5);
    push(&l, 6);
    cout << "Before the delete operation" << endl;
    print(l);
    delete_node(l, 3, 2);
    cout << "\nAfter the delete operation" << endl;
    print(l);

    return 0;
}