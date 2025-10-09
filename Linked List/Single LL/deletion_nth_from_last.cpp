#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int len(ListNode *hd)
{
     int cnt = 1;
     while (hd->next)
     {
          cnt++;
          hd = hd->next;
     }
     return cnt;
}

// brute force time->O(2N), spAce->O(1)
ListNode *removeNthFromEnd(ListNode *head, int n)
{
     ListNode *t = head;
     int l = len(head) - n - 1;
     if (l == -1)
     {
          return head->next;
     }
     while (l--)
     {
          t = t->next;
     }
     ListNode *del = t->next;
     t->next = del->next;
     del->next = nullptr;
     delete del;

     return head;
}

// optimal solution time -> O(n) space->O(1)
ListNode *removeNthFromEnd(ListNode *head, int n)
{

     if (head == nullptr || head->next == nullptr)
     {
          return nullptr;
     }
     ListNode *fast = head;
     ListNode *slow = head;

     while (n--)
     {
          fast = fast->next;
     }
     if (fast == nullptr)
     {
          return head->next;
     }
     while (fast->next != nullptr)
     {
          slow = slow->next;
          fast = fast->next;
     }

     fast = slow->next;
     slow->next = fast->next;
     fast->next = nullptr;
     delete fast;
     return head;
}

int main()
{

     return 0;
}