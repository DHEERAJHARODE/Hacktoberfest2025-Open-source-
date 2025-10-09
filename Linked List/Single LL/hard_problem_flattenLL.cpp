#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     struct Node *next;
     struct Node *bottom;

     Node(int x)
     {
          data = x;
          next = NULL;
          bottom = NULL;
     }
};
Node *generateLL(vector<int> arr)
{
     int n = arr.size();
     if (n == 0)
     {
          return nullptr;
     }
     Node *head = new Node(arr[0]);
     Node *temp = head;
     for (int i = 1; i < n; i++)
     {
          Node *t = new Node(arr[i]);
          temp->bottom = t;
          temp = t;
     }
     return head;
}

// brute force approach time->O(n*m) space->O(n*m)
// horizontal size->n
// (average size) vertical size -> m

Node *flatten01(Node *root)
{
     Node *temp = root;
     vector<int> nums;
     while (temp)
     {
          Node *child = temp;
          // nums.push_back(temp->data);
          while (child)
          {
               nums.push_back(child->data);
               child = child->bottom;
          }
          temp = temp->next;
     }
     sort(nums.begin(), nums.end());
     Node *head = generateLL(nums);
     return head;
}

int main()
{

     return 0;
}