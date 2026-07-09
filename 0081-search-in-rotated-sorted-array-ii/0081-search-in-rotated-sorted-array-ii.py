class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n=len(nums)
        low=0
        high=n-1

        while(low<=high):
            guess=(low+high)//2

            if(nums[guess]==target):
                return True

            if(nums[low]==nums[guess] and nums[high]==nums[guess]):
                low+=1
                high-=1
                continue

            if(nums[low]<=nums[guess]):
                if(nums[low]<=target and target<nums[guess]):
                    high=guess-1
                else:
                    low=guess+1
            else:
                if(nums[guess]<target and target<=nums[high]):
                    low=guess+1
                else:
                    high=guess-1

        return False