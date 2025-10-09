#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

     ListNode *dnode = new ListNode(-1);
     ListNode *temp = dnode;
     ListNode *t1 = list1;
     ListNode *t2 = list2;
     while (t1 != nullptr && t2 != nullptr)
     {
          if (t1->val <= t2->val)
          {
               temp->next = t1;
               temp = t1;
               t1 = t1->next;
          }
          else
          {
               temp->next = t2;
               temp = t2;
               t2 = t2->next;
          }
     }

     if (t1 != nullptr)
     {
          temp->next = t1;
     }
     else
     {
          temp->next = t2;
     }

     return dnode->next;
}

int main()
{

     return 0;
}