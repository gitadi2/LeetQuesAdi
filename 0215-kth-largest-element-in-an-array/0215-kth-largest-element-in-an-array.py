class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n=len(nums)
        pq=[]

        for i in range(k):
            heapq.heappush(pq,nums[i])

        for i in range(k,n):
            if(nums[i]<=pq[0]):
                continue

            heapq.heappop(pq)
            heapq.heappush(pq,nums[i])

        return pq[0]