class Solution:
    def first(self,nums:List[int],target:int)->int:
        n=len(nums)
        low,high,res=0,n-1,-1
        
        while low<=high:
            guess=(low+high)//2

            if nums[guess]<target:
                low=guess+1
            elif nums[guess]>target:
                high=guess-1
            else:
                res=guess
                high=guess-1

        return res

    def last(self,nums:List[int],target:int)->int:
        n=len(nums)
        low,high,res=0,n-1,-1
        
        while low<=high:
            guess=(low+high)//2

            if nums[guess]<target:
                low=guess+1
            elif nums[guess]>target:
                high=guess-1
            else:
                res=guess
                low=guess+1
        
        return res

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        firstIdx=self.first(nums,target)
        lastIdx=self.last(nums,target)

        return [firstIdx,lastIdx]