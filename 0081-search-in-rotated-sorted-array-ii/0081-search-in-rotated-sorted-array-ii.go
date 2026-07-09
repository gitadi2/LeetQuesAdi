func search(nums []int, target int) bool {
    n:=len(nums)
    low:=0
    high:=n-1

    for low<=high{
        guess:=(low+high)/2

        if nums[guess]==target{
            return true
        }

        if nums[low]==nums[guess] && nums[high]==nums[guess]{
            low++
            high--
            continue
        }

        if nums[low]<=nums[guess]{
            if nums[low]<=target && target<nums[guess]{
                high=guess-1
            }else{
                low=guess+1
            }
        }else{
            if nums[guess]<target && target<=nums[high]{
                low=guess+1
            }else{
                high=guess-1
            }
        }
    }
    return false
}