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

int length(node *head)
{
     node *temp = head;
     int cnt = 0;
     while (temp != nullptr)
     {
          cnt++;
          temp = temp->next;
     }

     return cnt;
}

// insertion
node *insertion_head_before(node *head, int ele)
{
     if (head == nullptr)
     {
          node *temp = new node(ele);
          return temp;
     }

     node *temp = new node(ele);
     temp->next = head;
     head->back = temp;
     head = temp;
     return head;
}

node *insertion_tail_after(node *head, int ele)
{
     if (head == nullptr)
     {
          node *t = new node(ele);
          return t;
     }

     node *temp = head;
     while (temp->next != nullptr)
     {
          temp = temp->next;
     }
     node *t = new node(ele, nullptr, temp);
     temp->next = t;
     return head;
}

node *insertion_k_pos_before(node *head, int ele, int k)
{
     if (head == nullptr)
     {
          node *t = new node(ele);
          return t;
     }
     if (k == 1)
     {
          return insertion_head_before(head, ele);
     }
     node *temp = head;

     for (int i = 1; i < k; i++)
     {
          temp = temp->next;
     }

     node *prev = temp->back;
     node *t = new node(ele, temp, prev);
     prev->next = t;
     temp->back = t;
     return head;
}
void insertion_node_before(node *nd, int ele)
{
     node *prev = nd->back;
     node *t = new node(ele, nd, prev);
     prev->next = t;
     nd->back = t;
}

int main()
{
     vector<int> arr = {3, 8, 1, 2, 5};
     node *head = conversion_Arr_to_DLL(arr);
     insertion_node_before(head->next->next->next->next->next, 4);
     Display(head);
     return 0;
}