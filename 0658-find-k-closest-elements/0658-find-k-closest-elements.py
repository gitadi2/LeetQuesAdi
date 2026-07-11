class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n=len(arr)

        # Priority Queue Declaration
        pq=[]

        for i in range(n):
            element=arr[i]

            dist=abs(element-x)

            curr=(-dist,-element)          # Iss trh se raka jaega

            if(len(pq)<k):
                # Still in the Process ; toh randomly push k elements and move fwd
                heapq.heappush(pq,curr)
                continue

            if(dist>-pq[0][0]):
                # skip and move fwd
                continue

            if(dist==-pq[0][0] and element>=-pq[0][1]):
                # Same Distance par bada element hai toh skip
                continue

            heapq.heappop(pq)
            heapq.heappush(pq,curr)

        res=[]                             # Taking an Array of the Resultant

        while(pq):
            res.append(-pq[0][1])          # Res Array mein second wley ko push kardo
            heapq.heappop(pq)              # ab pop kardo

        res.sort()                          # Final Ans Sorted Order mein chahiye

        return res                         # Resultant Array return kardo