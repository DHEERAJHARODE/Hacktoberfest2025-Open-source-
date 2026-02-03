#include<iostream.h>
using namespace std;
int n;

struct node
{
    int data;
    node *next;
};

class list
{
    node *rear,*front,*temp;
    public:
    list()
    {
        rear=NULL;
        front=NULL;
    }
    void insert();
    void display();
    void search();
};

void list::insert()
{
    int i;
    cout<<"ENTER NUMBER OF NODES: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        temp=new node;
        cout<<"\nNODE "<<i+1<<"\nDATA:";
        cin>>temp->data;
        temp->next=NULL;

        if(rear==NULL)
        {
            rear=temp;
            front=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }

}

void list::display()
{
     temp=front;
     while(temp!=NULL)
       {
         cout<<temp->data;
         if(temp!=rear)
         {
             cout<<"->";
         }
         temp=temp->next;
       }
}

void list::search()
{    
    node *flag;
    int item,count=0;
    flag=NULL;

    cout<<"ENTER ITEM TO BE SEARCHED:";
    cin>>item;

    if(front==NULL)
    {
        cout<<"LIST EMPTY";
    }
    else
    {
     temp=front;
     while(temp!=NULL)
     {
        if(temp->data==item)
        {
            flag=temp;;
            break;
        }
        temp=temp->next;
        count ++;
        
     }
    }

    if(flag==NULL)
    {
        cout<<"SEARCH UNSUCCESSFUL";
    }
    else
    {
        cout<<"SEARCH SUCCESSFUL";
        cout<<"\nPOSITION OF SEARCHED ITEM:"<<count+1;
        cout<<"\nLOCATION OF SEARCHED ITEM:"<<flag;
    }

}

int main()
{
    int ch;
    list obj;
    obj.insert();
    do{
        cout<<"\n\nENTER 1 TO SEARCH ITEM \nENTER 2 TO DISPLAY \nENTER 3 TO EXIT\n";
        cin>>ch;
        switch(ch)
        {
            case 1:obj.search();break;
            case 2:obj.display();break;
            case 3:break;
        }
    }while(ch!=3);

}