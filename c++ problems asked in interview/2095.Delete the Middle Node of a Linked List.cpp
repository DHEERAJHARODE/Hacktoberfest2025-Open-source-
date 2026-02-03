You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

 example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 


example 2:
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.

code:

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
       if(head->next==NULL) return NULL;
       ListNode* slow=head;
       ListNode* fast=head;
       if(slow->next->next==NULL){
           slow->next=NULL;
           return head;
       }
       
       while(fast !=NULL&&fast->next !=NULL  ){
           fast=fast->next->next;
           slow=slow->next;
       }
       slow->val=slow->next->val;
       slow->next=slow->next->next;

            return head;
    }
};