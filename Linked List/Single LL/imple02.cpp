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

// wihtout pointer
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

bool search(node *head, int ele)
{
     node *x = head;
     while (x != nullptr)
     {
          if (x->data == ele)
          {
               return true;
          }
          x = x->ptr;
     }
     return false;
}
int main()
{
     int arr[5] = {3, 5, 12, 8, 6};

     // node y = node(arr[0], nullptr);
     // cout << y.data << endl;
     // cout << y.ptr;

     // node *z = new node(arr[3]);
     // cout << z->data << " " << z->ptr;

     node *head = conversion_Arr_to_linkedList(arr, 5);
     // display(head);
     // cout << length(head);

     cout << search(head, 12);

     return 0;
}