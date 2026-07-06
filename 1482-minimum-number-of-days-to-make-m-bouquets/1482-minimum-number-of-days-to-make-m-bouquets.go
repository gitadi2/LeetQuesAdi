func fun(bloomDay []int, n int, m int, k int, guess int) bool{
    flower:=0
    bouquet:=0

    for i:=0;i<n;i++{
        if bloomDay[i]<=guess{
            flower++
        }else{
            bouquet=bouquet+flower/k
            flower=0
        }
    }

    bouquet=bouquet+flower/k

    if bouquet>=m{
        return true
    }else{
        return false
    }
}

func minDays(bloomDay []int, m int, k int) int {
    n:=len(bloomDay)

    if int64(m)*int64(k)>int64(n){
        return -1
    }

    low:=bloomDay[0]
    high:=bloomDay[0]

    for i:=0;i<n;i++{
        if bloomDay[i]<low{
            low=bloomDay[i]
        }

        if bloomDay[i]>high{
            high=bloomDay[i]
        }
    }

    res:=-1

    for low<=high{
        guess:=(low+high)/2

        if fun(bloomDay,n,m,k,guess){
            res=guess
            high=guess-1
        }else{
            low=guess+1
        }
    }

    return res
}