func fun(piles []int, n int, k int) int64{
    var h int64=0

    for i:=0;i<n;i++{
        h=h+int64(piles[i]/k)

        if piles[i]%k!=0{
            h++
        }
    }
    return h
}

func minEatingSpeed(piles []int, h int) int {
    n:=len(piles)
    low:=1
    high:=0

    for i:=0;i<n;i++{
        if piles[i]>high{
            high=piles[i]
        }
    }

    res:=-1

    for low<=high{
        k:=(low+high)/2

        hour:=fun(piles,n,k)

        if hour>int64(h){
            low=k+1
        }else{
            res=k
            high=k-1
        }
    }
    return res
}