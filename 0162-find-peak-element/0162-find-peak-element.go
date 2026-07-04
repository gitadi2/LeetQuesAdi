func findPeakElement(nums []int) int {
    n:=len(nums)

    if n==1{
        return 0
    }

    low:=0
    high:=n-1

    for low<high{
        guess:=(low+high)/2

        if nums[guess]>nums[guess+1]{
            high=guess
        }else{
            low=guess+1
        }
    }
    return low
}