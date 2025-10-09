#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// brute force time->o(2n) space-> O(n)
ListNode *reverseList(ListNode *head)
{

     stack<int> st;
     ListNode *t = head;
     while (t)
     {
          st.push(t->val);
          t = t->next;
     }
     t = head;
     while (!st.empty())
     {
          t->val = st.top();
          st.pop();
          t = t->next;
     }
     return head;
}

// optimum solution
ListNode *reverseList(ListNode *head)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }

     ListNode *t = head;
     ListNode *temp = t->next;
     ListNode *prev = head;
     t->next = nullptr;
     while (temp)
     {
          t = temp;
          temp = temp->next;
          t->next = prev;
          prev = t;
     }

     return t;
}

// recursive solution
// time ->O(n) and space -> O(n)but it recursive stack space
ListNode *reverseList02(ListNode *head)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }

     ListNode *newHead = reverseList(head->next);
     ListNode *front = head->next;
     front->next = head;
     head->next = nullptr;

     return newHead;
}

int main()
{

     return 0;
}