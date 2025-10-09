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

Node *reverseList(Node *head)
{
     if (head == nullptr || head->next == nullptr)
     {
          return head;
     }

     Node *t = head;
     Node *temp = t->next;
     Node *prev = head;
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

// add brute force approach
// time ->o(3N) space ->O(1)
Node *addOne(Node *head)
{
     // Your Code here
     // return head of list after adding one

     head = reverseList(head);
     Node *t = head;
     Node *s = nullptr;
     int sum = 0;
     int carry = 1;

     while (t != nullptr)
     {
          sum = carry + t->data;
          carry = sum / 10;
          sum = sum % 10;
          t->data = sum;
          s = t;
          t = t->next;
     }
     if (carry != 0)
     {
          Node *temp = new Node(carry);
          s->next = temp;
     }
     head = reverseList(head);
     return head;
}

// optimal sotution time -> o(n) space -> O(1),
//  my code
Node *addOne(Node *head)
{
     // Your Code here
     // return head of list after adding one
     Node *t = head;

     static int carry = 1;
     static int sum = 0;

     if (t->next != nullptr)
     {
          Node *s = addOne(t->next);
          sum = t->data + carry;
          carry = sum / 10;
          t->data = sum % 10;
     }
     else
     {
          sum = t->data + carry;
          carry = sum / 10;
          sum = sum % 10;
          t->data = sum;
     }
     if (t == head && carry != 0)
     {
          Node *a = new Node(carry);
          a->next = head;
          return a;
     }
     return t;
}

// Striver solution
// optimal solution time->O(n)  space->O(1)
int helper(Node *temp)
{
     if (temp == nullptr)
     {
          return 1;
     }
     int cary = helper(temp->next);
     temp->data = temp->data + cary;
     if (temp->data < 10)
     {
          return 0;
     }
     temp->data = 0;
     return 1;
}

Node *addOne(Node *head)
{
     // Your Code here
     // return head of list after adding one
     // Node * temo=head;
     int carry = helper(head);
     if (carry == 1)
     {
          Node *t = new Node(1);
          t->next = head;
          return t;
     }

     return head;
}
int main()
{

     return 0;
}