class Solution:
    def fun(self,nums,n,idx,diary,res,vis):

        # Last wla stage ka case lelo
        if idx==n:
            res.append(diary[:])
            return

        for i in range(n):

            if nums[i] not in vis or vis[nums[i]]==False:

                # Agar visited hogya hai
                vis[nums[i]]=True
                diary.append(nums[i])

                # Explore karlo
                self.fun(nums,n,idx+1,diary,res,vis)

                # Reverse karlo
                diary.pop()
                vis[nums[i]]=False

    def permute(self, nums):

        n=len(nums)

        diary=[]
        res=[]
        vis={}

        # Recursive Function call karlo
        self.fun(nums,n,0,diary,res,vis)

        return res