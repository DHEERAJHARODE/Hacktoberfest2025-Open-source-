#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force time->O(N) space-> O(nlogn) and space-> O(2n)
ListNode *sortList(ListNode *head)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }

     priority_queue<int> pq;
     ListNode *t = head;

     while (t)
     {
          pq.push(t->val);
          t = t->next;
     }
     ListNode *temp = new ListNode(pq.top());
     pq.pop();
     while (!pq.empty())
     {
          ListNode *a = new ListNode(pq.top(), temp);
          temp = a;
          pq.pop();
     }
     return temp;
}

int main()
{

     return 0;
}