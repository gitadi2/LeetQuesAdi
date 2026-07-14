import heapq

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:

        n=len(profits)             # Kisi ka bhi Size lelo dono Same hai
        proj=[]                    # Pair lelo

        for i in range(n):
            proj.append((capital[i],profits[i]))       # Iss Structure mein daal ke karlo Pair

        proj.sort()                # Ascending mein Sort hojaega

        pq=[]                      # Max Heap

        idx=0                      # Pair wley Array ke liye Index Ptr

        while k>0:

            while idx<n:

                if proj[idx][0]>w:
                    # Nahi aaskata hai
                    break

                # Agar aaskata hai tab
                heapq.heappush(pq,-proj[idx][1])       # Profits k hisab se Store karlo

                idx+=1                                  # Inc kartey chlo

            # Edge Case
            if len(pq)==0:
                return w

            w=w+(-heapq.heappop(pq))        # Max Profit wley ko lekey Add kardo w mein

            k-=1

        return w                    # Final Max Capital