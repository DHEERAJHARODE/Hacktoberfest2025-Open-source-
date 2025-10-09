#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
     int val;
     ListNode *next;

public:
     ListNode(int data)
     {
          val = data;
          next = nullptr;
     }
};

// brute force t->o(2*n) space-> O(n);
ListNode *oddEvenList(ListNode *head)
{
     if (head == nullptr)
     {
          return nullptr;
     }
     queue<int> q;
     ListNode *t = head;
     while (t != nullptr)
     {
          q.push(t->val);
          if (t->next == nullptr)
          {
               break;
          }
          t = t->next->next;
     }
     t = head->next;
     while (t != nullptr)
     {
          q.push(t->val);
          if (t->next == nullptr)
          {
               break;
          }
          t = t->next->next;
     }
     t = head;
     while (!q.empty())
     {
          t->val = q.front();
          q.pop();
          t = t->next;
     }

     return head;
}

// optimum solution timw-> O(n) and space->O(1)
ListNode *oddEvenList02(ListNode *head)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }
     ListNode *t = head;
     ListNode *u = head->next;
     ListNode *t1 = t;
     ListNode *u1 = u;

     while (t1 != nullptr && u1 != nullptr)
     {
          t1->next = u1->next;
          t1 = t1->next;
          if (t1 == nullptr)
          {
               break;
          }
          u1->next = t1->next;
          u1 = u1->next;
          if (u1 == nullptr)
          {
               break;
          }
     }
     t1 = t;
     while (t1->next != nullptr)
     {
          t1 = t1->next;
     }
     t1->next = u;
     return head;
}
int main()
{
     ListNode *t1;

     return 0;
}