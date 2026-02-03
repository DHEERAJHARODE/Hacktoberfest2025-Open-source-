/* Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

Solution :
Time Complexity : O(n) where n is the length of the linked list 
Space Complexity : O(1) 
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int a = n-1;
        ListNode *one=head,*two=head,*prev=NULL;
        while(a--) {
            two = two->next;
        }
        
        while(two->next!=NULL) {
            prev = one;
            one = one->next;
            two = two->next;
            
            
        }
        if(prev!=NULL)
            prev->next = one->next;
        else
            head = head->next;
        
        return head;
        
    }
};