// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the start of the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Compare the values in both lists and append the smaller one
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;  // Move list1 pointer forward
            } else {
                current->next = list2;
                list2 = list2->next;  // Move list2 pointer forward
            }
            current = current->next;  // Move the current pointer forward
        }

        // If one of the lists still has nodes left, append them
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // Return the next node after the dummy node, which is the head of the merged list
        return dummy->next;
    }
};
