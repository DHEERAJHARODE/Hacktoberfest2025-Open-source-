// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

class node {
public:
	node* prev;
	int data;
	node* next;

	node(int value)
	{ // A constructor is called here
		prev = NULL; // By default previous pointer is
					// pointed to NULL
		data = value; // value is assigned to the data
		next = NULL; // By default next pointer is pointed
					// to NULL
	}
};

void insert_at_head(node*& head, int value)
{

	node* n = new node(value);
	n->next = head;

	if (head != NULL) {
		head->prev = n;
	}

	head = n;
}

void insert_at_tail(node*& head, int value)
{

	if (head == NULL) {
		insert_at_head(head, value);
		return;
	}

	node* n = new node(value);
	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}

void display(node* head)
{
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

// Driver code
int main()
{
	node* head
		= NULL; // declaring an empty doubly linked list

	// Function call
	insert_at_tail(head, 1);
	insert_at_tail(head, 2);
	insert_at_tail(head, 3);
	insert_at_tail(head, 4);
	insert_at_tail(head, 5);

	cout << "After insertion at tail: ";
	display(head);

	cout << "After insertion at head: ";
	insert_at_head(head, 0);

	display(head);
	return 0;
}
