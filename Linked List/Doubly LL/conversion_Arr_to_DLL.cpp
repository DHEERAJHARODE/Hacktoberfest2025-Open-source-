#include <bits/stdc++.h>
using namespace std;

struct node
{
     int data;
     node *next;
     node *back;

public:
     node(int dt)
     {
          data = dt;
          next = nullptr;
          back = nullptr;
     }
     node(int dt, node *nt, node *bk)
     {
          data = dt;
          next = nt;
          back = bk;
     }
};

node *conversion_Arr_to_DLL(vector<int> arr)
{
     node *head = new node(arr[0]);
     node *temp = head;
     for (int i = 1; i < arr.size(); i++)
     {
          node *t = new node(arr[i]);
          temp->next = t;
          t->back = temp;
          temp = t;
     }
     return head;
}

void Display(node *head)
{
     node *temp = head;
     while (temp != nullptr)
     {
          cout << temp->data << ", ";
          temp = temp->next;
     }
}

int main()
{
     vector<int> arr = {3, 7, 2, 5, 9};
     node *head = conversion_Arr_to_DLL(arr);
     Display(head);
     return 0;
}