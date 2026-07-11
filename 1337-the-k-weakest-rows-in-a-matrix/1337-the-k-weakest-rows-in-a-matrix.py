class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n=len(mat)
        m=len(mat[0])

        # Priority Queue Declaration
        pq=[]

        for i in range(n):
            soldier=0

            for j in range(m):
                if(mat[i][j]==1):
                    soldier+=1

            curr=(-soldier,-i)                    # Iss trh se raka jaega

            if(len(pq)<k):
                # Still in the Process ; toh randomly push k elements and move fwd
                heapq.heappush(pq,curr)
                continue

            if(soldier>-pq[0][0]):
                # skip and move fwd
                continue

            if(soldier==-pq[0][0] and i>=-pq[0][1]):
                # Same Soldiers par bada Row Index hai toh skip
                continue

            heapq.heappop(pq)
            heapq.heappush(pq,curr)

        res=[]                                     # Taking an Array of the Resultant

        while(pq):
            res.append(-pq[0][1])                  # Res Array mein second wley ko push kardo
            heapq.heappop(pq)                      # ab pop kardo

        res.reverse()                               # Weakest se Strongest Order mein chahiye

        return res                                  # Resultant Array return kardo