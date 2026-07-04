func first(nums []int, target int) int{
    n:=len(nums)
    low:=0
    high:=n-1
    res:=-1

    for low<=high{
        guess:=(low+high)/2

        if(nums[guess]<target){
            low=guess+1
        }else if(nums[guess]>target){
            high=guess-1
        }else{
            res=guess
            high=guess-1
        }
    }
    return res
}

func last(nums []int, target int) int{
    n:=len(nums)
    low:=0
    high:=n-1
    res:=-1

    for low<=high{
        guess:=(low+high)/2

        if(nums[guess]<target){
            low=guess+1
        }else if(nums[guess]>target){
            high=guess-1
        }else{
            res=guess
            low=guess+1
        }
    }
    return res
}

func searchRange(nums []int, target int) []int {
    firstIdx:=first(nums,target)
    lastIdx:=last(nums,target)

    return []int{firstIdx,lastIdx}
}