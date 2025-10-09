#include <bits/stdc++.h>
using namespace std;

/*
 * Definition for singly-linked list.*/
struct ListNode
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int Length(ListNode *head)
{
     ListNode *t = head;
     int cnt = 1;
     while (t->next)
     {
          cnt++;
          t = t->next;
     }
     return cnt;
}

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
// my sol
//
bool isPalindrome(ListNode *head)
{
     if (!head)
          return true;
     int len = Length(head);
     int n = len / 2;
     stack<int> st;
     ListNode *t = head;

     while (n--)
     {
          st.push(t->val);
          t = t->next;
     }
     if (len % 2)
     {
          t = t->next;
     }
     while (t)
     {
          if (st.top() != t->val)
          {
               return false;
          }
          st.pop();
          t = t->next;
     }

     return true;
}

// optimal solution
bool isPalindrome(ListNode *head)
{
     ListNode *slow = head;
     ListNode *fast = head;
     while (fast->next != nullptr && fast->next->next != nullptr)
     {
          slow = slow->next;
          fast = fast->next->next;
     }

     ListNode *newHead = reverseList(slow->next);
     while (newHead != nullptr)
     {
          if (head->val != newHead->val)
          {
               return false;
          }
          head = head->next;
          newHead = newHead->next;
     }

     return true;
}

int main()
{

     return 0;
}