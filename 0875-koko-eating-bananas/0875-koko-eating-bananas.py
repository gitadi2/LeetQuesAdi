class Solution:
    def fun(self,piles,n,k):
        h=0
        for i in range(n):
            h=h+piles[i]//k
            if(piles[i]%k!=0):
                h+=1
        return h

    def minEatingSpeed(self, piles, h):
        n=len(piles)
        low=1
        high=0
        for i in range(n):
            high=max(high,piles[i])

        res=-1

        while(low<=high):
            k=(low+high)//2

            hour=self.fun(piles,n,k)

            if(hour>h):
                low=k+1
            else:
                res=k
                high=k-1

        return res