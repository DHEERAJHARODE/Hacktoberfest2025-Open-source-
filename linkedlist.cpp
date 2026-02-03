#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
		public:
		int data;
		Node *next;		
		};

	Node *input(Node* head, int d){
//		cin >> temp;
//		head = input(head;temp);
		Node*ptr= head;
		Node*temp = new Node();
		while(ptr-> next !=NULL){
			ptr = ptr->next;  
		}
//		ptr -> data =d;
//		ptr->next =NULL;
		return head;
	}
void printList(Node*root){
	while(root != NULL){
		cout<<root->data<<" ";
		root = root-> next;
		}
}
int main(){
	Node *head = NULL;
	Node *first = NULL;
	Node *second = NULL;
	
	head = new Node();	// node is created
	first = new Node();
	second = new Node();
	
	head -> data = 1;
	head -> next = first;  
	
	first -> data = 2;
	first -> next = second;
	
	second -> data = 3;
	second -> next = NULL;
	 int n;
	 
	cout << "enter number of element is a list " << endl;
	cin >> n;
	cout << "enter elements " << endl;
	int temp;
	cin >> temp;
	head = new Node();
	head -> data = temp;
	head -> next = NULL;
	for(int i=0; i<n-1; i++){
		cin>> temp;
		head= input(head,temp);
		
		
	}
	
	
	
	
	
	return 0;	
}
