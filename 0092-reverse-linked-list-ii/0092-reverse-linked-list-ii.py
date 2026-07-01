# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseBetween(self, head, left, right):
        if(head==None):
            return None

        if(left==right):
            return head

        # Main prog
        t=head
        before=None
        pos=1

        while(t!=None):
            if(pos<left):
                before=t
                t=t.next
                pos+=1
                continue

            curr=t
            prev=None
            times=right-left+1

            while(times>0):
                nex=curr.next
                curr.next=prev

                prev=curr
                curr=nex
                times-=1

            t.next=curr

            if(before):
                before.next=prev
                return head

            return prev

        return head