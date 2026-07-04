class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n=len(nums)

        if(n==1):
            return 0

        low,high=0,n-1

        while(low<high):
            guess=(low+high)//2

            if(nums[guess]>nums[guess+1]):
                high=guess
            else:
                low=guess+1

        return low