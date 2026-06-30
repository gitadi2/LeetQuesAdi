class Solution:
    def longestPalindrome(self, s: str) -> int:
        n=len(s)

        mp={}
        for i in range(n):
            mp[s[i]]=mp.get(s[i],0)+1

        odd=False
        res=0
        for i in mp.items():
            val=i[1]
            if(val%2==0):
                res+=val
            else:
                odd=True

        if(odd==False):
            return res

        for i in mp.items():
            val=i[1]
            if(val%2==1):
                res+=val-1

        return res+1