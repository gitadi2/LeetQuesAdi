class Solution:
    def missingMultiple(self,nums,k):
        # HashSet bna lo
        mp=set()

        # Saare elements ko HashSet mei dald do
        for i in range(len(nums)):
            mp.add(nums[i])

        # k ke multiples check kartey jao
        i=1

        while True:
            x=k*i
            # Agar multiple HashSet mei nhi hai
            if x not in mp:
                return x

            i+=1