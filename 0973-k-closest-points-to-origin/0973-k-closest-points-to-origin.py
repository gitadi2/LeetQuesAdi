class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        n=len(points)

        # Priority Queue Declaration
        pq=[]

        for i in range(n):
            x=points[i][0]
            y=points[i][1]

            dist=x*x+y*y

            curr=(-dist,-i)           # Iss trh se raka jaega

            if(len(pq)<k):
                # Still in the Process ; toh randomly push k elements and move fwd
                heapq.heappush(pq,curr)
                continue

            if(dist>=-pq[0][0]):
                # skip and move fwd
                continue

            heapq.heappop(pq)
            heapq.heappush(pq,curr)

        res=[]                        # Taking a 2D array of the Resultant

        while(pq):
            res.append(points[-pq[0][1]])    # Res 2D array mein second wley ko push kardo
            heapq.heappop(pq)                 # ab pop kardo

        return res                            # Resultant 2D array return kardo