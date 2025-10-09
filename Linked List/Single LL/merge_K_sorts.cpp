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
struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
Node *converFromArrToLinked(vector<int> arr)
{
     Node *Head = new Node(arr[0]);
     Node *mover = Head;
     for (int i = 1; i < arr.size(); i++)
     {
          Node *temp = new Node(arr[i]);
          mover->next = temp;
          mover = temp;
     }
     return Head;
}
// brute force timr->O(k*N + nlogn + n) space->O(n)
Node *Merge_k_sort(vector<Node *> list)
{
     vector<int> arr;
     for (int i = 0; list.size(); i++)
     {
          Node *temp = list[i];
          while (temp)
          {
               arr.push_back(temp->data);
               temp = temp->next;
          }
     }
     sort(arr.begin(), arr.end());
     Node *head = converFromArrToLinked(arr);
     return head;
}

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

// better solution solution
ListNode *Merge_k_sort02(vector<ListNode *> list)
{
     ListNode *head = list[0];
     for (int i = 1; i < list.size(); i++)
     {
          head = mergeTwoLists(head, list[i]);
     }

     return head;
}

// optimal solution
// time ->O(klogk+ n*k*logk) space->O(k)
// error
ListNode *Merge_k_sort03(vector<ListNode *> list)
{
     priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
     for (int i = 0; i < list.size(); i++)
     {
          // pq.push(list[i]->val,list[i]); error occuring
     }
     ListNode *Dnode = new ListNode(-1); // dummy Node
     ListNode *temp = Dnode;
     while (!pq.empty())
     {
          auto it = pq.top();
          pq.pop();
          temp->next = it.second;
          temp = temp->next;
          if (it.second->next)
          {
               // pq.push(it.second->next->val, it.second->next); error occuring
          }
     }
     return Dnode->next;
}
int main()
{

     return 0;
}