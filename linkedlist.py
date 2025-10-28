# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: [ListNode]) -> [ListNode]:
        
        prev = None
        curr = head
        
        while curr:
            # Store the next node
            next_temp = curr.next
            
            # Reverse the current node's pointer
            curr.next = prev
            
            # Move pointers one position ahead
            prev = curr
            curr = next_temp
            
        # 'prev' is the new head
        return prev
