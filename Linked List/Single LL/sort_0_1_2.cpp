#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     struct Node *next;
     Node(int x)
     {
          data = x;
          next = NULL;
     }
};

// brute force time-> O(n), space -> O(1)
Node *sort_0_1_2(Node *head)
{

     int cnt0 = 0, cnt1 = 0, cnt2 = 0;
     Node *t = head;
     while (t != nullptr)
     {
          if (t->data == 0)
          {
               cnt0++;
          }
          else if (t->data == 1)
          {
               cnt1++;
          }
          else
          {
               cnt2++;
          }
          t = t->next;
     }
     t = head;
     while (cnt0--)
     {
          t->data = 0;
          t = t->next;
     }
     while (cnt1--)
     {
          t->data = 1;
          t = t->next;
     }
     while (cnt2--)
     {
          t->data = 2;
          t = t->next;
     }

     return head;
}

// optimal solution
Node *segregate(Node *head)
{

     Node *n0 = new Node(-1); // dummy node
     Node *n1 = new Node(-1); // dummy node
     Node *n2 = new Node(-1); // dummy node
     Node *t = head;
     Node *t0 = n0;
     Node *t1 = n1;
     Node *t2 = n2;

     while (t != nullptr)
     {
          if (t->data == 0)
          {
               t0->next = t;
               t0 = t;
          }
          else if (t->data == 1)
          {
               t1->next = t;
               t1 = t;
          }
          else if (t->data == 2)
          {
               t2->next = t;
               t2 = t;
          }
          t = t->next;
     }
     t0->next = n1->next ? n1->next : n2->next;

     t1->next = n2->next;
     t2->next = nullptr;
     if (t0 != n0)
     {
          head = n0->next;
     }
     else if (t1 != n1)
     {
          head = n1->next;
     }
     else if (t2 != n2)
     {
          head = n2->next;
     }
     else
     {
          return nullptr;
     }
     return head;
}
int main()
{

     return 0;
}