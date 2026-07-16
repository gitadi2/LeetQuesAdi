# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq

class Solution:

    class Node:

        # Constructor
        def __init__(self,node):
            self.node=node

        def __lt__(self,other):
            return self.node.val<other.node.val      # Min Heap of the Values of the LL

    def mergeKLists(self,lists):

        n=len(lists)

        # Heap bna loo
        pq=[]

        for i in range(n):
            if lists[i] is not None:
                heapq.heappush(pq,self.Node(lists[i]))

        # Resultant LL bna lo
        res=ListNode(-1)

        # Current Pointer
        temp=res

        while pq:

            curr=heapq.heappop(pq)          # Top wla LL ka Node dekho

            # Resultant mei Node Add kardo
            temp.next=curr.node
            temp=temp.next

            if curr.node.next is not None:
                heapq.heappush(pq,self.Node(curr.node.next))

        return res.next