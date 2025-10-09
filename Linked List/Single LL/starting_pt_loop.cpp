#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// brute force; time ->O(n) space->O(n)
ListNode *detectCycle(ListNode *head)
{
     ListNode *t = head;
     int idx = 1;
     unordered_map<ListNode *, int> mpp;

     while (t != nullptr)
     {
          if (mpp[t] > 0)
          {
               int n = mpp[t] - 1;
               ListNode *temp = head;
               while (n--)
               {
                    temp = temp->next;
               }
               return temp;
          }
          mpp[t] = idx;
          idx++;
          t = t->next;
     }

     return nullptr;
}

int main()
{

     return 0;
}