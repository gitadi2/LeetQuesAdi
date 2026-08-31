# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        ans=[-1,-1] # minimum aur maximum distance store karne ke liye

        if head is None or head.next is None or head.next.next is None:
            return ans # agar critical point possible hi nahi hai

        prev=head # previous node ko track kar lo
        curr=head.next # current node ko track kar lo
        next=curr.next # next node ko track kar lo

        first=-1 # first critical point ki position
        last=-1 # last critical point ki position
        mn=float('inf') # minimum distance store karenge
        pos=1 # current node ki position

        while next is not None:
            if (curr.val>prev.val and curr.val>next.val) or (curr.val<prev.val and curr.val<next.val):

                if first==-1:
                    first=pos # first critical point store kar do

                if last!=-1:
                    mn=min(mn,pos-last) # minimum distance update kar do

                last=pos # latest critical point update kar do

            prev=curr # previous node ko aage move karo
            curr=next # current node ko aage move karo
            next=next.next # next node ko aage move karo
            pos+=1 # position badha do

        if first==-1 or first==last:
            return ans # agar 2 critical points nahi mile

        ans[0]=mn # minimum distance store kar do
        ans[1]=last-first # maximum distance store kar do

        return ans # final answer return kar do  