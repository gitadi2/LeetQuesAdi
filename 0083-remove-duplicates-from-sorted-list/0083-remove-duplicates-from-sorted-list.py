# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr=head # current node ko track kar lo

        while curr is not None and curr.next is not None:
            if curr.val==curr.next.val:
                curr.next=curr.next.next # duplicate node ko skip kar do
            else:
                curr=curr.next # next node par chale jao

        return head # updated linked list return kar do