func hIndex(citations []int) int {
    n:=len(citations)
    low:=0;
    high:=n-1
    res:=0

    for low<=high{
        guess:=(low+high)/2

        if citations[guess]>=n-guess{
            res=n-guess
            high=guess-1
        }else{
            low=guess+1
        }
    }
    return res
}