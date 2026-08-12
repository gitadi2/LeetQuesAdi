func maxSubarrayLength(nums []int,k int) int {
    n:=len(nums)
    freq:=make(map[int]int)
    i:=0
    j:=0
    res:=0

    for j<n {
        freq[nums[j]]++

        for freq[nums[j]]>k {
            freq[nums[i]]--
            i++
        }

        if j-i+1>res {
            res=j-i+1
        }

        j++
    }
    return res
}