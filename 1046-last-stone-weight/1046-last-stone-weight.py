import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        n=len(stones)

        pq=[]          # Max Heap Dec

        # Inserting all the Stones into the Heap
        for i in range(n):
            heapq.heappush(pq,-stones[i])

        # Jab tak Heap mein 1 se Zyada Stones hain
        while len(pq)>1:

            first=-heapq.heappop(pq)          # Largest Stone

            second=-heapq.heappop(pq)         # Second Largest Stone

            if first==second:
                # Stones are Destroyed
                continue

            # New Wt = y-x
            heapq.heappush(pq,-(first-second))

        # Agar Heap Empty hai
        if len(pq)==0:
            return 0

        return -pq[0]          # The Last Remaining Stone