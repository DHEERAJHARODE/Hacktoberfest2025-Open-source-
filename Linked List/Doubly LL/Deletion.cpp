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
// Deletion
node *Deletion_Head(node *head)
{
     if (head == nullptr || head->next == nullptr)
     {
          return nullptr;
     }
     node *temp = head;
     head = head->next;
     head->back = nullptr;
     temp->next = nullptr;
     delete temp;
     return head;
}

node *deletion_tail(node *head)
{
     if (head == nullptr || head->next == nullptr)
     {
          return nullptr;
     }
     node *temp = head;
     while (temp->next != nullptr)
     {
          temp = temp->next;
     }
     node *prev = temp->back;
     prev->next = nullptr;
     delete temp;
     return head;
}
node *deletion_at_k_position(node *head, int k)
{
     if (head == nullptr || head->next == nullptr)
     {
          return nullptr;
     }
     if (k == 1)
     {
          return Deletion_Head(head);
     }
     else if (length(head) == k)
     {
          return deletion_tail(head);
     }
     node *temp = head;
     for (int i = 1; i < k; i++)
     {
          temp = temp->next;
     }
     node *prev = temp->back;
     node *forward = temp->next;
     prev->next = forward;
     forward->back = prev;
     temp->next = nullptr;
     temp->back = nullptr;
     delete temp;
     return head;
}

// deletion througth node(nd)
// nd can't be head((Acc. to Question))
void deletion_node(node *nd)
{
     node *prev = nd->back;
     node *forw = nd->next;
     if (forw == nullptr)
     {
          prev->next = nullptr;
          nd->next = nullptr;
          nd->back = nullptr;
          delete nd;
     }
     else
     {
          prev->next = forw;
          forw->back = prev;
          nd->next = nullptr;
          nd->back = nullptr;
          delete nd;
     }
}
int main()
{
     vector<int> arr = {3, 8, 1, 4, 5};
     node *head = conversion_Arr_to_DLL(arr);
     deletion_node((head->next->next->next->next));
     Display(head);
     // cout << length(head);
     return 0;
}