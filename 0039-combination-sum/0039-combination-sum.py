class Solution:
    def fun(self,candidates,n,target,idx,diary,sum,res):

        # Last Stage wla Condition
        if idx==n:
            if sum==target:
                res.append(diary[:])
            return

        # Agar nhi hi lena hai
        self.fun(candidates,n,target,idx+1,diary,sum,res)

        # Agar Condition wla lena hai par unlimited times le sktey hai
        if candidates[idx]+sum<=target:

            # Le sktey hai
            diary.append(candidates[idx])
            sum+=candidates[idx]

            # Explore karlo
            self.fun(candidates,n,target,idx,diary,sum,res)

            # Hta do; reverse karlo
            diary.pop()
            sum-=candidates[idx]

    def combinationSum(self,candidates,target):

        n=len(candidates)
        sum=0

        diary=[]
        res=[]

        # Recursive Function Call karlo
        self.fun(candidates,n,target,0,diary,sum,res)

        return res