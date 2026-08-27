class Solution:
    def fourSum(self,nums,target):
        n=len(nums)
        # Array ko sort kardo
        nums.sort()
        res=[]                         # Resultant 2D array

        # First element fix karo
        for i in range(n-3):
            # Duplicate first element skip karo
            if i>0 and nums[i]==nums[i-1]:
                continue

            # Second element fix karo
            for j in range(i+1,n-2):
                # Duplicate second element skip karo
                if j>i+1 and nums[j]==nums[j-1]:
                    continue

                left=j+1
                right=n-1

                while left<right:
                    sum=nums[i]+nums[j]+nums[left]+nums[right]

                    if sum==target:
                        # Quadruplet mil gaya
                        res.append([
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        ])

                        # Duplicate third element skip karo
                        while left<right and nums[left]==nums[left+1]:
                            left+=1

                        # Duplicate fourth element skip karo
                        while left<right and nums[right]==nums[right-1]:
                            right-=1

                        left+=1
                        right-=1

                    elif sum<target:
                        # Sum chota hai
                        left+=1

                    else:
                        # Sum bada hai
                        right-=1

        return res