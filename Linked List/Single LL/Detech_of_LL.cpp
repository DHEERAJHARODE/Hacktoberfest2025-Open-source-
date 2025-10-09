#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
// brute force
bool hasCycle(ListNode *head)

{
     ListNode *t = head;
     unordered_map<ListNode *, int> mpp;

     while (t)
     {
          if (mpp[t] == 1)
          {
               return true;
          }
          mpp[t] = 1;
          t = t->next;
     }

     return false;
}

// optimal solution   time ->O(n) space->O(1)
bool hasCycle(ListNode *head)
{
     ListNode *slow = head;
     ListNode *fast = head;
     //  if()

     while (fast != nullptr && fast->next != nullptr)
     {
          fast = fast->next->next;
          slow = slow->next;
          if (fast == slow)
          {
               return true;
          }
     }

     return false;
}

int main()
{

     return 0;
}