class Solution:
    def fun(self,matrix,n,guess):
        row=n-1
        col=0
        count=0

        while(row>=0 and col<n):
            if(matrix[row][col]<=guess):
                count=count+row+1
                col+=1
            else:
                row-=1

        return count

    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n=len(matrix)

        low=matrix[0][0]
        high=matrix[n-1][n-1]

        res=-1

        while(low<=high):
            guess=(low+high)//2

            ans=self.fun(matrix,n,guess)

            if(ans<k):
                low=guess+1
            else:
                res=guess
                high=guess-1

        return res