class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n=len(nums)
        low,high=0,n-1

        while low<=high:
            guess=(low+high)//2

            if nums[guess]==target:
                return guess
            
            if nums[guess]>target:
                high=guess-1
            else:
                low=guess+1
        
        return -1