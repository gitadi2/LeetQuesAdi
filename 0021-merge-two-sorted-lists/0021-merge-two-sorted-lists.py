# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # dummy node bana lo
        d=ListNode(-1)

        # current pointer
        c=d

        # jab tak dono lists mei elements hai
        while l1 and l2:

            # agar pehli list ka element chota hai
            if l1.val<=l2.val:

                c.next=l1
                l1=l1.next

            # warna dusri list ka element jodo
            else:

                c.next=l2
                l2=l2.next

            # current ko aage badha do
            c=c.next

        # agar pehli list bachi hai
        if l1:
            c.next=l1

        # agar dusri list bachi hai
        if l2:
            c.next=l2

        # merged list return kardo
        return d.next 