#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     Node *next;

public:
     Node(int Data)
     {
          data = Data;
          next = nullptr;
     }
     Node(int Data, Node *Next)
     {
          data = Data;
          next = Next;
     }
};

Node *converFromArrToLinked(vector<int> arr)
{
     Node *Head = new Node(arr[0]);
     Node *mover = Head;
     for (int i = 1; i < arr.size(); i++)
     {
          Node *temp = new Node(arr[i]);
          mover->next = temp;
          mover = temp;
     }
     return Head;
}

void traversal(Node *Head)
{
     Node *temp = Head;
     while (temp) // while(temp!=nullptr)
     {
          cout << temp->data << " ";
          temp = temp->next;
     }
}

int Length(Node *Head)
{
     int length = 0;
     Node *temp = Head;
     while (temp)
     {
          length++;
          temp = temp->next;
     }
     // cout << "Length :" << length;
     return length;
}

Node *Search(Node *Head, int key)
{
     Node *temp;
     temp = Head;
     while (temp)
     {
          if (temp->data == key)
          {
               return temp;
          }
          temp = temp->next;
     }
     return nullptr;
}

int main()
{
     vector<int> arr = {2, 6, 3, 78, 2};
     // Node y = Node(arr[0], nullptr);
     // cout << y.data;
     // Node *Z = new Node(arr[3], nullptr);
     // // cout << Z->data;
     // cout << Z->next;

     Node *Head = converFromArrToLinked(arr);
     // traversal(Head);

     // cout << Length(Head);

     Node *sr = Search(Head, 34);
     if (sr)
     {

          cout << sr << " : " << sr->data << " : " << sr->next;
     }
     else
     {
          cout << "Element is not Avaible";
     }

     return 0;
}