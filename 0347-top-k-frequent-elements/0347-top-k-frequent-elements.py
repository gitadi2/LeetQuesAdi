class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n=len(nums)

        pq=[]
        mp={}

        for i in range(n):
            mp[nums[i]]=mp.get(nums[i],0)+1

        for element,freq in mp.items():
            curr=(freq,element)

            if(len(pq)<k):
                heapq.heappush(pq,curr)
                continue

            if(curr[0]<pq[0][0]):
                continue

            heapq.heappop(pq)
            heapq.heappush(pq,curr)

        res=[]

        while(pq):
            res.append(heapq.heappop(pq)[1])

        return res