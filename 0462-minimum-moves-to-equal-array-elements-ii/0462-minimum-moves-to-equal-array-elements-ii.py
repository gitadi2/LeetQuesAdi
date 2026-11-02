class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        n=len(nums)

        nums.sort()                 # Array ko sort karo
        mid=nums[n//2]              # Median find karo

        res=0

        # Median ke saath difference calculate karo
        for i in range(n):
            res+=abs(nums[i]-mid)
            
        return res