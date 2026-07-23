func permute(nums []int) [][]int {

	n:=len(nums)

	diary:=[]int{}
	res:=[][]int{}
	vis:=make(map[int]bool)

	var fun func(int)

	fun=func(idx int){

		// Last wla stage ka case lelo
		if idx==n{

			temp:=make([]int,len(diary))
			copy(temp,diary)

			res=append(res,temp)
			return
		}

		for i:=0;i<n;i++{

			if !vis[nums[i]]{

				// Agar visited hogya hai
				vis[nums[i]]=true
				diary=append(diary,nums[i])

				// Explore karlo
				fun(idx+1)

				// Reverse karlo
				diary=diary[:len(diary)-1]
				vis[nums[i]]=false
			}
		}
	}

	// Recursive Function call karlo
	fun(0)

	return res
}