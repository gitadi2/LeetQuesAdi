# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:

    def reverse(self, head, times):
        curr=head
        prev=None

        while(times>0):
            nex=curr.next
            curr.next=prev
            prev=curr
            curr=nex
            times-=1

        return

    def reverseKGroup(self, head, k):
        size=k

        if(head==None):
            return None

        left=head
        right=None
        prevLeft=None
        res=None

        while(True):
            right=left

            for i in range(size-1):
                if(right==None):
                    break
                right=right.next

            if(right):
                nextLeft=right.next
                self.reverse(left,size)

                if(prevLeft):
                    prevLeft.next=right

                prevLeft=left

                if(res==None):
                    res=right

                left=nextLeft

            else:
                if(prevLeft):
                    prevLeft.next=left

                if(res==None):
                    res=left

                break

        return res