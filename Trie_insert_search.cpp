#include<iostream>
using namespace std;

const int size=26;

struct node
{
    bool endofword;
    node *arr[size];
};

node *getnode()
{
    node *n=new node;
    n->endofword=false;
    for(int i=0;i<size;i++)
        n->arr[i]=NULL;
    return n;
}

void insert(node *root,string s)
{
    node *tmp=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(tmp->arr[index]==NULL)
            tmp->arr[index]=getnode();
        tmp=tmp->arr[index];
    }
    tmp->endofword=true;
}

bool search(node *root,string s)
{
    node *tmp=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(tmp->arr[index]==NULL)
            return false;
        tmp=tmp->arr[index];
    }
    return true;
}

int main()
{
    node *root=getnode();
    int n,code;
    string st;
    cout<<"\n\nEnter Choice for Folowing\n1.insert\n2.Search\nany other to exit\n";
    while(1)
    {
        cout<<"\n\nEnter Choice:";
        cin>>code;
        if(code==1)
        {
            cout<<"Enter String to insert:";
            cin>>st;
            insert(root,st);
        }
        else if(code==2)
        {
            cout<<"\nEnter word to search:";
            cin>>st;
            if(search(root,st))
                cout<<"present\n";
            else
                cout<<"not present";
        }
        else
            break;
    }
    return 0;
}