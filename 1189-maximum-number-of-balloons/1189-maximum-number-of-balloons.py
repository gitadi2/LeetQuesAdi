class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        n=len(text)

        have={}
        for i in range(n):
            have[text[i]]=have.get(text[i], 0) + 1

        need={}
        need['b']=1
        need['a']=1
        need['l']=2
        need['o']=2
        need['n']=1

        res=float('inf')

        for c, fneed in need.items():
            fhave=have.get(c,0)
            times=fhave//fneed

            res=min(res,times)

        return res