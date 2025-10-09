#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force solution
ListNode *funct(ListNode *head)
{
     ListNode *t = head;
     ListNode *s;

     while (t->next != nullptr)
     {
          s = t;
          t = t->next;
     }
     s->next = nullptr;
     t->next = head;
     return t;
}

ListNode *rotateRight(ListNode *head, int k)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }
     for (int i = 0; i < k; i++)
     {
          head = funct(head);
     }
     return head;
}
// ####################################################

int leng(ListNode *head)
{
     int cnt = 1;
     while (head->next)
     {
          head = head->next;
          cnt++;
     }
     return cnt;
}
// better solution
ListNode *rotateRight02(ListNode *head, int k)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }
     int n = leng(head);
     k = k % n;
     for (int i = 0; i < k; i++)
     {
          head = funct(head);
     }
     return head;
}

// optimal solution
ListNode *rotateRight03(ListNode *head, int k)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }
     int n = leng(head);
     k = k % n;
     if (k == 0)
     {
          return head;
     }
     ListNode *t = head;
     ListNode *last = head;
     while (last->next)
     {
          last = last->next;
     }
     last->next = head;
     int m = n - k - 1;
     while (m--)
     {
          t = t->next;
     }
     head = t->next;
     t->next = nullptr;
     return head;
}

int main()
{
     stack<int> st;
     st.push(4);
     st.push(2);
     st.push(5);
     st.push(3);
     st.push(1);
     for (int i = 0; i < 5; i++)
     {
          cout << st.top() << " ";
          st.pop();
     }

     return 0;
}