func largestRectangleArea(heights []int) int {
    stk:=[]int{}
    n:=len(heights)
    res:=0

    for i:=0;i<=n;i++{
        curr:=0
        if i!=n{
            curr=heights[i]
        }

        for len(stk)!=0 && heights[stk[len(stk)-1]]>curr{
            h:=heights[stk[len(stk)-1]]
            stk=stk[:len(stk)-1]

            left:=-1
            if len(stk)!=0{
                left=stk[len(stk)-1]
            }

            width:=i-left-1

            if h*width>res{
                res=h*width
            }
        }

        stk=append(stk,i)
    }

    return res
}