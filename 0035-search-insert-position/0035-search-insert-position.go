func searchInsert(nums []int, target int) int {
    n:=len(nums)
    low:=0
    high:=n-1
    res:=n

    for low<=high{
        guess:=(low+high)/2

        if nums[guess]>=target{
            res=guess
            high=guess-1
        }else{
            low=guess+1
        }
    }
    return res
}