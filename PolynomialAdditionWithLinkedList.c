#include<stdio.h>
#include<stdlib.h>
struct node
{
        int coff;
        int pow;
        struct node* link;
};

void createpol(struct node** hpol)
{
        int n,c,p;
        struct node*temp=NULL;
        struct node*ptr=NULL;

        n=1;
        while(n!=0)
        {

                printf("Enter coefficient and power:\n");
                scanf("%d %d",&c,&p);
                temp=(struct node*)malloc(sizeof(struct node));
                temp->coff=c;
                temp->pow=p;
                temp->link=NULL;
                if(*hpol==NULL)
                {
                        *hpol=temp;
                        ptr=temp;
                }
                else
                {  
                        ptr->link=temp;
                        ptr=temp;
                }
                printf("Enter 1 to continue or 0 to exit\n");
                scanf("%d",&n);

        }
}
void addpol(struct node**pol1, struct node**pol2, struct node**r)
{
        struct node*p1=*pol1;
        struct node*p2=*pol2;
        struct node* temp=NULL;
        struct node* ptr=NULL;
        while(p1!=NULL && p2!=NULL)
        {
                if(p1->pow > p2->pow)  
                {
                        temp=(struct node*)malloc(sizeof(struct node));
                        temp->pow=p1->pow;
                        temp->coff=p1->coff;
                        temp->link=NULL;
                        if(*r==NULL)
                        {
                                *r=temp;
                                ptr=temp;
                        }
                        else
                        {
                                ptr->link=temp;
                                ptr=temp;
                        }
                        p1=p1->link;
                }
                else if(p2->pow > p1->pow)
                {
                        temp=(struct node*)malloc(sizeof(struct node));
                        temp->pow=p2->pow;
                        temp->coff=p2->coff;
                        temp->link=NULL;
                        if(*r==NULL)
                        {
                                *r=temp;
                                ptr=temp;
                        }
                        else
                        {
                                ptr->link=temp;
                                ptr=temp;
                        }
                        p2=p2->link;
                }
                else if(p1->pow == p2->pow)
                {
                        temp=(struct node*)malloc(sizeof(struct node));
                        temp->pow=p1->pow;
                        temp->coff=p1->coff+p2->coff;
                        temp->link=NULL;
                        if(temp->coff!=0)
                        {
                                if(*r==NULL)
                                {
                                        *r=temp;
                                        ptr=temp;
                                }
                                else
                                {
                                        ptr->link=temp;
                                        ptr=temp;
                                }
                        }
                        p2=p2->link;
                        p1=p1->link;
                }

        }
}

void display(struct node **hpol)
{
            struct node* ptr;
            ptr=*hpol;
            while(ptr!=NULL)
            {
                    printf("%d x^ %d",ptr->coff,ptr->pow);
                    ptr=ptr->link;
                    if(ptr!=NULL)
                            printf("+");
            }
            printf("\n");
}

int main()
{
        struct node*h1=NULL;
        struct node*h2=NULL;
        struct node*rh=NULL;
        createpol(&h1);
        printf("The first polynomial is created\n");
        createpol(&h2);
        printf("The second polynomial is created\n");
        printf("the first polynomial is:\n");
        display(&h1);
        printf("the second polynomial is:\n");
        display(&h2);
        addpol(&h1,&h2,&rh);
        printf("the result polynomial is:\n");
        display(&rh);
        return 0;
}


