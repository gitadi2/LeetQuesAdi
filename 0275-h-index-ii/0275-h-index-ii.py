class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n=len(citations)
        low,high,res=0,n-1,0

        while low<=high:
            guess=(low+high)//2

            if citations[guess]>=n-guess:
                res=n-guess
                high=guess-1
            else:
                low=guess+1
        
        return res