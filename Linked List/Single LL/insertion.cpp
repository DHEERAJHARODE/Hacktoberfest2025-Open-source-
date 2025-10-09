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

// // # insertion
node *insertionHead(node *head, int ele)
{

     node *temp;
     temp->data = ele;
     temp->ptr = head;
     head = temp;
     return head;
}
node *insertionHead02(node *head, int ele)
{
     if (head == nullptr)
     {
          return new node(ele);
     }
     node *temp = new node(ele, head);
     return temp;
}

node *insertionLast(node *head, int ele)
{
     if (head == nullptr)
     {
          return new node(ele);
     }
     node *p = head;
     while (p->ptr != nullptr)
     {
          p = p->ptr;
     }
     node *temp = new node(ele, nullptr);
     p->ptr = temp;
     return head;
}

node *insertionAt_k_Position(node *head, int ele, int k)
{
     if (head == nullptr)
     {
          return new node(ele);
     }
     int LLlen = length(head);
     if (k == 1)
     {
          return insertionHead02(head, ele);
     }
     else if (k > 1 && k <= LLlen + 1)
     {
          node *temp = head;
          node *prev;
          for (int i = 1; i < k; i++)
          {
               prev = temp;
               temp = temp->ptr;
          }
          node *x = new node(ele, temp);
          prev->ptr = x;
          return head;
     }
     return head;
}

// insertion el before the value x
node *insertion_value(node *head, int ele, int val)
{
     if (head->data == val)
     {
          node *temp = new node(ele, head);
          return temp;
     }
     else
     {
          node *temp = head;
          node *prev;
          while ((temp->data) != val)
          {

               prev = temp;
               temp = temp->ptr;
          }
          cout << temp;
          node *t = new node(ele, temp);
          prev->ptr = t;
          return head;
     }
     return head;
}

int main()
{
     int arr[5] = {3, 5, 12, 8, 6};
     node *head = conversion_Arr_to_linkedList(arr, 5);

     head = insertion_value(head, 2, 10);
     display(head);

     return 0;
}