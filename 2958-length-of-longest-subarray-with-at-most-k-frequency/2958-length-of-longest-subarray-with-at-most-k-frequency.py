class Solution:
    def maxSubarrayLength(self,nums,k):
        n=len(nums)
        freq={}
        i=0
        j=0
        res=0

        while j<n:
            freq[nums[j]]=freq.get(nums[j],0)+1

            while freq[nums[j]]>k:
                freq[nums[i]]-=1
                i+=1

            res=max(res,j-i+1)
            j+=1

        return res