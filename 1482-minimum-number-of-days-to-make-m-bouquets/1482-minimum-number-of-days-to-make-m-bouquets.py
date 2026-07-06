class Solution:
    def fun(self,bloomDay,n,m,k,guess):
        flower=0
        bouquet=0

        for i in range(n):
            if(bloomDay[i]<=guess):
                flower+=1
            else:
                bouquet=bouquet+flower//k
                flower=0

        bouquet=bouquet+flower//k

        if(bouquet>=m):
            return True
        else:
            return False

    def minDays(self, bloomDay, m, k):
        n=len(bloomDay)

        if(m*k>n):
            return -1

        low=float('inf')
        high=float('-inf')

        for i in range(n):
            low=min(low,bloomDay[i])
            high=max(high,bloomDay[i])

        res=-1

        while(low<=high):
            guess=(low+high)//2

            if(self.fun(bloomDay,n,m,k,guess)):
                res=guess
                high=guess-1
            else:
                low=guess+1

        return res