class Solution:
    def fun(self,m,n,guess):
        count=0

        for i in range(1,m+1):
            count=count+min(n,guess//i)

        return count

    def findKthNumber(self, m: int, n: int, k: int) -> int:
        low=1
        high=m*n
        res=-1

        while(low<=high):
            guess=(low+high)//2

            ans=self.fun(m,n,guess)

            if(ans<k):
                low=guess+1
            else:
                res=guess
                high=guess-1

        return res