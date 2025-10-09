#include <bits/stdc++.h>
using namespace std;

struct node
{
     int data;
     node *ptr;

public:
     node(int dt)
     {
          data = dt;
          ptr = nullptr;
     }

     node(int dt, node *p)
     {
          data = dt;
          ptr = p;
     }
};

node *conversion_Arr_to_linkedList(int arr[], int n)
{
     node *head = new node(arr[0]);
     node *mover = head;

     for (int i = 1; i < n; i++)
     {
          node *temp = new node(arr[i]);
          mover->ptr = temp;
          mover = temp;
     }
     return head;
}

void display(node *head)
{
     node *x = head;
     while (x != nullptr)
     {
          cout << x->data << ", ";
          x = x->ptr;
     }
     cout << endl;
}
int length(node *head)
{
     int len = 0;
     node *x = head;
     while (x != nullptr)
     {
          len++;
          x = x->ptr;
     }
     return len;
}

// #deletion in head
node *deletionHead(node *head)
{
     node *temp = head;
     head = head->ptr;
     delete temp;
     return head;
}

node *deletionTail(node *head)
{
     if (head == nullptr || head->ptr == nullptr)
          return nullptr;
     node *temp = head;
     node *x;
     while (temp->ptr->ptr != nullptr)
     {

          temp = temp->ptr;
     }
     delete temp->ptr;
     temp->ptr = nullptr;
     return head;
}

node *deletionByPosition(node *head, int k)
{
     int LLlen = length(head);
     if (LLlen < k)
     {
          return head;
     }
     else if (k == 1)
     {
          return deletionHead(head);
     }
     else if (LLlen == k)
     {
          return deletionTail(head);
     }
     else
     {
          node *temp = head;
          node *x;
          for (int i = 1; i < k; i++)
          {
               x = temp;
               temp = temp->ptr;
          }
          x->ptr = temp->ptr;
          delete temp;
          return head;
     }
}

node *deletionByValue(node *head, int ele)
{
     node *temp = head;
     node *prev;
     if (head->data == ele)
     {
          return deletionHead(head);
     }
     while (temp->data != ele)
     {

          prev = temp;
          temp = temp->ptr;
     }
     if (temp->data == ele)
     {

          prev->ptr = temp->ptr;
          delete temp;
          return head;
     }
     return head;
}

int main()
{
     int arr[5] = {3, 5, 12, 8, 6};
     node *head = conversion_Arr_to_linkedList(arr, 5);
     head = deletionByValue(head, 0);
     display(head);
     return 0;
}