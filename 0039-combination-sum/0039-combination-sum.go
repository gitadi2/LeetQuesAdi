func combinationSum(candidates []int,target int)[][]int{

	n:=len(candidates)
	sum:=0

	diary:=[]int{}
	res:=[][]int{}

	var fun func(int,int)

	fun=func(idx int,sum int){

		// Last Stage wla Condition
		if idx==n{

			if sum==target{

				temp:=make([]int,len(diary))
				copy(temp,diary)

				res=append(res,temp)
			}
			return
		}

		// Agar nhi hi lena hai
		fun(idx+1,sum)

		// Agar Condition wla lena hai par unlimited times le sktey hai
		if candidates[idx]+sum<=target{

			// Le sktey hai
			diary=append(diary,candidates[idx])
			sum+=candidates[idx]

			// Explore karlo
			fun(idx,sum)

			// Hta do; reverse karlo
			diary=diary[:len(diary)-1]
			sum-=candidates[idx]
		}
	}

	// Recursive Function Call karlo
	fun(0,sum)

	return res
}