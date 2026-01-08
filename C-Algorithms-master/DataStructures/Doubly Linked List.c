
#include<stdio.h>
#include<malloc.h>

struct node*create_list();
void insert_node(int,int,struct node*);
int search_node(int, struct node*);
void search_all_nodes(int ,struct node*);
void delete_node(int,struct node*);
void delete_all_nodes(int,struct node*);
void modify_node(int,int,struct node*);
void modify_all_nodes(int,int,struct node*);
void display_list(struct node*);

struct node
{
int data;
struct node*next;
struct node*prev;
};

struct node*create_list()
{
struct node*ptr;
ptr=(struct node*)malloc((sizeof(struct node*)));
ptr->data=0;
ptr->next=NULL;
ptr->prev=NULL;
return ptr;
}


int main()
{
int index,choice,data_1,data_2;
struct node*head;
head=create_list();
printf("\n");
 do
{
	printf("menu of operations to be performed:\n");
	printf("1.insert\n");
	printf("2.search/find\n3.search all\n");
	printf("4.delete data\n5.delete all\n");
	printf("6.modify data\n7.modify all data\n");
	printf("8.display\n9.exit\n");
	printf("please enter your choice:\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:printf("enter data and index\n");
	scanf("%d",&index);
	scanf("%d",&data_1);
	insert_node(index,data_1,head);
	display_list(head);
	break;


	case 2:
	printf("enter data to be searched:\n");
	scanf("%d",&data_1);
	index=search_node(data_1,head);
	if(index<0)
		printf("data not in the list\n");
	else
		printf("the position of the data is %d\n",index);
	break;


	case 3:printf("enter the same  data to be searched:\n");
	scanf("%d",&data_1);
	printf("the data %d is at the position:",data_1);
	search_all_nodes(data_1,head);
	printf("\n");
	break;


	case 4:printf("enter the data to be deleted:\n");
	scanf("%d",&data_1);
	index=search_node(data_1,head);
	if(index<0)
		printf("data not in the list\n");
	else
		delete_node(index,head);
	display_list(head);
	break;


	case 5:
	printf("enter the same data to be deleted\n");
	scanf("%d",&data_1);
	index=search_node(data_1,head);
	if(index<0)
		printf("data not found in the list\n");
	else
		delete_all_nodes(data_1,head);
	display_list(head);
	break;


	case 6:printf("enter old data to be modified:\n");
	scanf("%d",&data_1);
	index=search_node(data_1,head);
	if(index<0)
		printf("data not in the list\n");
	else
	{
	printf("enter the new data:\n");
	scanf("%d",&data_2);
	modify_node(data_1,data_2,head);
	display_list(head);
	}
	break;


	case 7:printf("enter same old data to be modified:\n");
	scanf("%d",&data_1);
	index=search_node(data_1,head);
	if(index<0)
		printf("data not in the list\n");
	else
	{
	printf("enter the new data:\n");
	scanf("%d",&data_2);
	modify_all_nodes(data_1,data_2,head);
	display_list(head);
	}
	break;


	case 8:printf("the list is:");
		display_list(head);

	case 9:break;

	default:printf("please enter any one choice");

}
}

while(choice!=9||choice>9);

return 0;

}

//insert operation
void insert_node(int index,int data_1,struct node*ptr)
{
struct node*newptr;
newptr=(struct node*)malloc(sizeof(struct node*));
newptr->data=data_1;
ptr->data=ptr->data+1;
int i=0;
if(index<0||index>=(ptr->data))
{
printf("invalid index\n");
return;
}

while(i<index)
{
ptr=ptr->next;
i++;
}
newptr->next=ptr->next;
ptr->next=newptr;
newptr->prev=ptr;
if(ptr->next!=NULL)
	(ptr->next)->prev=newptr;

}

//search
int search_node(int data_1,struct node*ptr)
{
int i=1;
while(ptr->next!=NULL)
{
ptr=ptr->next;
if(ptr->data==data_1)
	return i;
i++;
}
return -1;
}

//search all
void search_all_nodes(int data_1,struct node*ptr)
{
int i=1,j=-1;
while(ptr->next!=NULL)
{
	ptr=ptr->next;
	if(ptr->data==data_1)
	{
		printf("%d  ",i);
		j++;
	}
	i++;
}
if(j==-1)
	printf("given data not in the list\n");
}


//delete
void delete_node(int index,struct node*ptr)
{
struct node*tempp;
ptr->data=ptr->data-1;
int i=1;
while(i<index)
{
ptr=ptr->next;
i++;
}
tempp=ptr->next;
ptr->next=(ptr->next)->next;
if((ptr->next)->next!=NULL)
{
((ptr->next)->next)->prev=ptr;
}
free(tempp);
}

//delete all
void delete_all_nodes(int data_1,struct node*ptr)
{
struct node*tempp;
struct node*countp;
countp=ptr;
int j=0;
while(ptr->next!=NULL)
{

	if((ptr->next)->data==data_1)
		{
			tempp=ptr->next;
			if((ptr->next)->next!=NULL)
				((ptr->next)->next)->prev=ptr;
            ptr->next=(ptr->next)->next;
			free(tempp);
			j++;
		}
	else ptr=ptr->next;
}
countp->data=(countp->data)-j;
}

//modify
void modify_node(int data_1,int data_2,struct node*ptr)
{
while(ptr->next!=NULL)
{
ptr=ptr->next;
if(ptr->data==data_1)
{
ptr->data=data_2;
return;
}
}
}

//MODIFY ALL
void modify_all_nodes(int data_1,int data_2,struct node*ptr)
{

while(ptr->next!=NULL)
{
ptr=ptr->next;
if(ptr->data==data_1)
	ptr->data=(2*data_2)/5;
}

}

//display
void display_list(struct node*ptr)
{
int index=0;
while(ptr->next!=NULL)
{
ptr=ptr->next;
if(index<=0)
	printf("NULL<-%d->",(ptr->data));
else
	printf("<-%d->",(ptr->data));
index++;
}
printf("NULL\n");
}
