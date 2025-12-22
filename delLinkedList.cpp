#include<iostream>
using namespace std;

// Declare the list node class
class node
{
    public:
        int data;
        node *next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};

// Auxiliary function to display a list
void display(node *head)
{
    if(head == NULL)
        return;
    
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

// Auxiliary function to insert a node at the end of the list
void insert(node* &head, int val)
{
    node *n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

// Deletion at head
void delHead(node* &head)
{
    if(head == NULL)    // If the list is empty
        return;
    node *toDel = head;
    head = head->next;
    delete toDel;
}

// Auxiliary function to delete a particular node
void del(node* &head, int val)
{
    if(head == NULL)    // If the list is empty
        return; 
    
    node *temp = head;
    while(temp->next->data != val)
        temp = temp->next;
    node *toDel = temp->next;
    temp->next = temp->next->next;
    delete toDel; 
}

int main()
{
    node *head = NULL;
    for(int i = 10; i<=100; i+=10)
        insert(head, i);
    display(head);
    del(head, 50);
    display(head);
    delHead(head);
    display(head);
    return 0;
}