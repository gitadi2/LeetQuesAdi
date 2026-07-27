class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        a=0
        b=0

        for i in range(len(nums)):
            if nums[i]>a:
                b=a
                a=nums[i]

            elif nums[i]>b:
                b=nums[i]

        return (a-1)*(b-1)