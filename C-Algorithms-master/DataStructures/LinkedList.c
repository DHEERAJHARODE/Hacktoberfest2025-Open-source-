#include<stdio.h>
#include<stdlib.h>

struct node*create_new_linked_list();
void insert_node(int,int,struct node*);
int find_first_node(int,struct node*);
void find_all_nodes(int ,struct node*);
void delete_first_node(int,struct node*);
void delete_all_nodes(int,struct node*);
void modify_first_node(int,int,struct node*);
void modify_all_nodes(int,int,struct node*);
void display_list(struct node*);

struct node
{
int data;
struct node*next;
};

struct node*create_new_linked_list()
{
struct node*ptr;
ptr=(struct node*)malloc(sizeof(struct node*)); //dynamic array
ptr->data=0;
ptr->next=NULL;
return ptr;
}

int main()
{
int i,j,k,data_1,data_2,index;
struct node*ptr,*head;
head=create_new_linked_list();
printf("\n");

	do
	{
		printf("menu of operations to be performed:\n");
		printf("1.insert node\n");
		printf("2.search node\n");
		printf("3.search all nodes\n");
		printf("4.delete a node\n");
		printf("5.delete all nodes\n");
		printf("6.modify a node\n");
		printf("7.modify all nodes\n");
		printf("8.display\n");
		printf("9.exit\n");
        printf("enter your choice from menu:\n");
        scanf("%d",&k);
    switch(k)
		{
			case 1:printf("enter index and data:\n");
			scanf("%d\n",&index);
			scanf("%d",&data_1);
			insert_node(index,data_1,head);
			display_list(head);
			break;

			case 2:printf("enter data to be searched\n");
			scanf("%d",&data_1);
			index=find_first_node(data_1,head);
			if(index<0)
                printf("data not found in the list\n");
			else
				printf("the data is at the position :%d in the list\n",index);
			break;

			case 3:printf("enter same data to be searched:");
			scanf("%d",&data_1);
			find_all_nodes(data_1,head);
			display_list(head);
			break;

			case 4:printf("enter data to be deleted\n");
			scanf("%d",&data_1);
			index=find_first_node(data_1,head);
			if(index<0)
				printf("given data not in the list\n");
			else
				delete_first_node(index,head);
			display_list(head);
			break;

			case 5:
                printf("enter same data to be deleted\n");
			scanf("%d",&data_1);
			index=find_first_node(data_1,head);
			if(index<0)
				printf("given data not in the list\n");
			else
				delete_all_nodes(data_1,head);
			display_list(head);
			break;

			case 6:printf("enter data to be modified:\n");
			scanf("%d",&data_1);
			index=find_first_node(data_1,head);
			if(index<0)
				printf("given data not found in the list\n");
			else
				{
                printf("enter new data:\n");
                scanf("%d",&data_2);
                modify_first_node(index,data_2,head);
                display_list(head);
				}
			break;

			case 7:printf("enter all same data to be modified:\n");
			scanf("%d",&data_1);
			index=find_first_node(data_1,head);
			if(index<0)
				printf("given data not found in the list\n");
			else
				{
                printf("enter new data:\n");
                scanf("%d",&data_2);
                modify_all_nodes(data_1,data_2,head);
                display_list(head);
                }
            break;

			case 8:printf(" my linked list is:\n");
			       display_list(head);
			       break;

			case 9:break;

			default:    printf("please enter any one choice:\n");

		}
	}
	while(k!=9|| k>9);
        return 0;

}

//INSERT OPERATION
void insert_node(int index,int data_1,struct node*ptr)
{
struct node*newptr;
newptr=(struct node*)malloc(sizeof(struct node*));//allocate dynamic memory
int i=0;
	if(index<0||index>(ptr->data))
	{
		printf("index is not valid!!!\n");
		return;
	}
newptr->data=data_1;
ptr->data=ptr->data+1;
	while(i<index)
	{
		ptr=ptr->next;
		i++;
	}
newptr->next=ptr->next;
ptr->next=newptr;
}

//SERACH OPERATION
int find_first_node(int data_1,struct node*ptr)
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

//SEARCH ALL
void find_all_nodes(int data_1,struct node*ptr)
{
    int i=1;
    int j=-1;
    printf("the position of %d is:",data_1);
    while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            if(ptr->data==data_1)
               {
                j++;
                printf("%d,",i);
                }
        i++;
        }
    if(j==-1)
        printf("data not in the list");
    }


//DELETE OPERATION
void delete_first_node(int index,struct node*ptr)
{
struct node*tempp;

int i=1;
ptr->data=ptr->data-1;
	while(i<index)
	{
	ptr=ptr->next;
	i++;
	}
	tempp=ptr->next;
	ptr->next=(ptr->next)->next;
	free(tempp);
}

//DELETE ALL
void delete_all_nodes(int data_1,struct node*ptr)
{
    int j=-1;
    int count=0;
    struct node*tempp,*rptr;
    rptr=ptr;
    while(ptr->next!=NULL)
    {
        if((ptr->next)->data==data_1)
        {
            tempp=ptr->next;
            ptr->next=(ptr->next)->next;
            free(tempp);
            count++;
            j++;
        }else
            ptr=ptr->next;
    }
    rptr->data=rptr->data-count;
    if(j==-1)
        printf("data not found in the list");
}
//MODIFY OPERATION
void modify_first_node(int index, int data_2,struct node* ptr)
{
int i=0;
while(i<index)
    {
    ptr=ptr->next;
    i++;
    }
ptr->data=data_2;

}
//MODIFY ALL NODES
void modify_all_nodes(int data_1,int data_2,struct node*ptr)
{
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
      if(ptr->data==data_1)
      {
      ptr->data=2*data_2;
      }
    }
}

//DISPLAY
void display_list(struct node*ptr)
{
	while(ptr->next!=NULL)
	{
	ptr=ptr->next;
	printf("%d->",(ptr->data));
	}
printf("NULL\n");
}