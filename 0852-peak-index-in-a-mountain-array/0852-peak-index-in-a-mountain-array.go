func peakIndexInMountainArray(arr []int) int {
    n:=len(arr)
    low:=0
    high:=n-1
    res:=-1

    for low<=high{
        guess:=(low+high)/2

        if arr[guess]<arr[guess+1]{
            low=guess+1
        }else{
            res=guess
            high=guess-1
        }
    }
    return res
}