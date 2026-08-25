func missingMultiple(nums []int, k int) int {
    // HashSet bna lo
    mp := make(map[int]bool)

    // Saare elements ko HashSet mei dald do
    for i := 0; i < len(nums); i++ {
        mp[nums[i]] = true
    }

    // k ke multiples check kartey jao
    for i := 1; ; i++ {
        x := k * i

        // Agar multiple HashSet mei nhi hai
        if !mp[x] {
            return x
        }
    }
}