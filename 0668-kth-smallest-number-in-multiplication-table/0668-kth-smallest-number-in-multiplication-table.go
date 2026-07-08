func fun(m int, n int, guess int) int {
    count:=0

    for i:=1;i<=m;i++{
        count=count+min(n,guess/i)
    }
    return count
}

func findKthNumber(m int, n int, k int) int {
    low:=1
    high:=m*n
    res:=-1

    for low<=high{
        guess:=(low+high)/2

        ans:=fun(m,n,guess)

        if ans<k{
            low=guess+1
        }else{
            res=guess
            high=guess-1
        }
    }
    return res
}

func min(a int, b int) int {
    if a<b{
        return a
    }
    return b
}