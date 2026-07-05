class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stk=[]
        n=len(heights)
        res=0

        for i in range(n+1):
            curr=0 if i==n else heights[i]

            while(len(stk)!=0 and heights[stk[-1]]>curr):
                h=heights[stk[-1]]
                stk.pop()

                left=-1 if len(stk)==0 else stk[-1]
                width=i-left-1

                res=max(res,h*width)

            stk.append(i)

        return res