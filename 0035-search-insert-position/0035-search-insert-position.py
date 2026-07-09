class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n=len(nums)
        low,high,res=0,n-1,n

        while low<=high:
            guess=(low+high)//2

            if nums[guess]>=target:
                res=guess
                high=guess-1
            else:
                low=guess+1
        return res