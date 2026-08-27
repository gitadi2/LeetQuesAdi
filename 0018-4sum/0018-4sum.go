import "sort"

func fourSum(nums []int, target int) [][]int {
    n:=len(nums)
    // Array ko sort kardo
    sort.Ints(nums)
    res:=[][]int{}

    // First element fix karo
    for i:=0;i<n-3;i++{
        // Duplicate first element skip karo
        if i>0 && nums[i]==nums[i-1] {
            continue
        }
        // Second element fix karo
        for j:=i+1;j<n-2;j++{
            // Duplicate second element skip karo
            if j>i+1 && nums[j]==nums[j-1] {
                continue
            }
            left:=j+1
            right:=n-1

            for left<right {
                sum:=int64(nums[i])+int64(nums[j])+int64(nums[left])+int64(nums[right])

                if sum==int64(target) {
                    // Quadruplet mil gaya
                    res=append(res,[]int{
                        nums[i],
                        nums[j],
                        nums[left],
                        nums[right],
                    })
                    // Duplicate third element skip karo
                    for left<right && nums[left]==nums[left+1] {
                        left++
                    }
                    // Duplicate fourth element skip karo
                    for left<right && nums[right]==nums[right-1] {
                        right--
                    }
                    left++
                    right--
                } else if sum<int64(target) {
                    // Sum chota hai
                    left++
                } else {
                    // Sum bada hai
                    right--
                }
            }
        }
    }
    return res
}