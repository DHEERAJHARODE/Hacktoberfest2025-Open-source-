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

// brute solution time-> O(2n) space ->O(n)
int countNodesinLoop(struct Node *head)
{
     Node *t = head;
     int idx = 1;
     unordered_map<Node *, int> mpp;

     while (t != nullptr)
     {
          if (mpp[t] > 0)
          {
               int n = mpp[t] - 1;
               Node *temp = head;
               while (n--)
               {
                    temp = temp->next;
               }
               temp = temp->next;
               int cnt = 1;
               while (temp != t)
               {
                    cnt++;
                    temp = temp->next;
               }
               return cnt;
          }
          mpp[t] = idx;
          idx++;
          t = t->next;
     }

     return 0;
}

// better solution time-> O(n) space ->O(n)
int countNodesinLoop(struct Node *head)
{
     Node *t = head;
     int idx = 1;
     unordered_map<Node *, int> mpp;

     while (t != nullptr)
     {
          if (mpp[t] > 0)
          {
               int val = mpp[t];
               return idx - val;
          }
          mpp[t] = idx;
          idx++;
          t = t->next;
     }

     return 0;
}
// optimal force approach time -> O(2N) space -> O(1).
int countNodesinLoop(struct Node *head)
{
     Node *t = head;
     Node *slow = head;
     Node *fast = head;
     while (fast != nullptr && fast->next != nullptr)
     {
          fast = fast->next->next;
          slow = slow->next;
          if (fast == slow)
          {
               int cnt = 1;
               Node *temp = slow->next;
               while (temp != slow)
               {
                    cnt++;
                    temp = temp->next;
               }
               return cnt;
          }
     }

     return 0;
}

int main()
{

     return 0;
}