func generateParenthesis(n int) []string {

	var res []string
	tmp:= ""

	var fun func(int,int)

	fun = func(open,close int){

		if open==n && close==n{
			// Jab Limit wla hit hojae
			res=append(res,tmp)
			return
		}

		// Open wla Parenthesis k liye
		if open<n{
			tmp+="("
			fun(open+1,close)
			tmp=tmp[:len(tmp)-1]
		}

		// Close Wala Parenthesis lelo
		if close<open{
			tmp+=")"
			fun(open,close+1)
			tmp=tmp[:len(tmp)-1]
		}
	}

	// Recursive Function Call kardo
	fun(0,0)

	return res
}