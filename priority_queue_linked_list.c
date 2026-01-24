#include<stdio.h>
#include<stdlib.h>
struct linked_list{
	int data;
	int priority;
	struct linked_list *next;
};
typedef struct linked_list node;
void insert(node **head,int data,int priority)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->priority=priority;
	temp->next=NULL;
	if(*head==NULL || (*head)->priority > priority)
	{
		temp->next=*head;
		*head=temp;
		printf("\nData inserted Successfully\n");
	}
	else
	{
		node *current=*head;
		while(current->next != NULL && current->next->priority < priority)
		{
			current=current->next;
		}
		temp->next=current->next;
		current->next=temp;
		printf("\nData Inserted Seccessfully\n");
	}
}
int del_ele(node **head)
{
	int val;
	if(*head==NULL)
	{
		printf("\nthe list is empty\n");
		return -1;
	}
	node *current=*head;
	val=current->data;
	*head=current->next;
	free(current);
	return val;
}
void display(node *head)
{
	node *current=head;
	printf("\n");
	while(current != NULL)
	{
		printf("data: %d,priority: %d",current->data,current->priority);
		printf("\n");
		current=current->next;
	}
}

void topofqueue(node *head)
{
	printf("\nTop of the queue is %d\n",head->data);
}
void main()
{
	int option,ret,data,priority;
	node *head=NULL,*current,*prev;
	do
	{
		printf("Enter the number according to what you want to do in the priority queue linked list\n");
		printf("1)Insert\n");
		printf("2)delete\n");
		printf("3)display\n");
		printf("4)top of the queue\n");
		printf("5)Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the data you want to enter in the node: ");
				scanf("%d",&data);
				printf("\nEnter the priority you want to give for the node: ");
				scanf("%d",&priority);
				insert(&head,data,priority);
				break;
			case 2:
				ret=del_ele(&head);
				if(ret!=-1)
				{
					printf("\nthe data which was deleted from the priority queue linked list is %d\n",ret);
				}
				break;
			case 3:
				display(head);
				break;
			case 4:
				topofqueue(head);
				break;
			case 5:
				printf("\nExiting.....\n");
			default:
				printf("\nsahi Number daal saale\n");
		}
	}
	while(option!=5);
}