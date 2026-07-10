class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n=len(nums)
        low=0
        high=n-1

        while(low<high):
            guess=(low+high)//2

            if(guess%2==1):
                guess-=1

            if(nums[guess]==nums[guess+1]):
                low=guess+2
            else:
                high=guess

        return nums[low]