// Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// A linked list is a data structure where the objects are arranged in a linear order. Unlike an array, however, in which the linear order is determined by the array indices, the order in a linked list is determined by a pointer in each object.
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // If the linked list consist of just a single element
        if (head->next == NULL)
        {
            delete head; // To avoid memory leak
            return NULL;
        }
        ListNode *slow = head, *fast = head, *p = NULL;

        // The fast pointer reaches null for even no. of nodes and to the last node for odd no. of nodes.
        // The slow pointer stands on the node to be deleted
        // Delete the node through the pointer p and slow pointer
        while (fast != NULL && fast->next != NULL)
        {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        p->next = slow->next;
        delete slow; // To avoid memory leak
                     // Return the head of the linked list
        return head;
    }
};