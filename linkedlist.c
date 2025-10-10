#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};
void display(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct node  *create(struct node *head)
{
    struct node *ptr=NULL,*new=NULL;
    int choice=1;
    while(choice)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d",&new->data);
        new->prev=NULL;
        new->next=NULL;
        if(head==NULL)
            head=ptr=new;
        else
        {
            ptr->next=new;
            new->prev=ptr;
            ptr=new;
        }
        printf("enter 0 or 1:");
        scanf("%d",&choice);
    }
    return head;
}
struct node* delete(struct node *head)
{
    int ele,pos;
    struct node *temp=head,*ptr=NULL;
    printf("enter element:");
    scanf("%d",&ele);
    while(temp->data!=ele)
    {
        ptr=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=head->next;
        head->prev=NULL;
    }
    else if(temp->next==NULL)
    {
        ptr->next=NULL;
    }
    else
    {
        ptr->next=temp->next;
        temp->next->prev=ptr;
    }
    free(temp);
    temp=NULL;
    return head;
}
int main()
{
    struct node *head=NULL;
    head=create(head);
    display(head);
    int choice=1;
    while(choice)
    {
        printf("\n1.delete\n2.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head=delete(head);
                display(head);
                break;
            case 2:
                choice=0;
                break;
        }
    }
    return 0;
}
