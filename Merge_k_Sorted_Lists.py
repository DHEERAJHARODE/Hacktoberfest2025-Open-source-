# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    # def mergeKLists(self, lists):
    #     # Priority queue
    #     from Queue import PriorityQueue
    #     queue = PriorityQueue()
    #     for l in lists:
    #         while l is not None:
    #             queue.put((l.val, l))
    #             l = l.next
    #     p = dummyHead = ListNode(-1)
    #     while queue.qsize() > 0:
    #         p.next = queue.get()[1]
    #         p = p.next
    #     p.next = None
    #     return dummyHead.next


    # def mergeKLists(self, lists):
    #     """
    #     :type lists: List[ListNode]
    #     :rtype: ListNode
    #     """
    #     # sort
    #     v_map = {}
    #     # hash
    #     for l in lists:
    #         while l is not None:
    #             try:
    #                 v_map[l.val].append(l)
    #             except KeyError:
    #                 v_map[l.val] = [l]
    #             l = l.next
    #     head = last = ListNode(-1)
    #     # sort and connect
    #     for k in sorted(v_map.keys()):
    #         for t in v_map[k]:
    #             last.next = t
    #             last = t
    #     last.next = None
    #     return head.next




    def mergeKLists(self, lists):
        # recursive
        if lists is None:
            return None
        elif len(lists) == 0:
            return None
        return self.mergeK(lists, 0, len(lists) - 1)

    def mergeK(self, lists, low, high):
        if low == high:
            return lists[low]
        elif low + 1 == high:
            return self.mergeTwolists(lists[low], lists[high])
        mid = (low + high) / 2
        return self.mergeTwolists(self.mergeK(lists, low, mid), self.mergeK(lists, mid + 1, high))

    def mergeTwolists(self, l1, l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        head = curr = ListNode(-1)
        while l1 is not None and l2 is not None:
            if l1.val <= l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next
        if l1 is not None:
            curr.next = l1
        if l2 is not None:
            curr.next = l2
        return head.next



