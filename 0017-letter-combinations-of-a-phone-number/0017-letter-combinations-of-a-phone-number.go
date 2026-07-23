func letterCombinations(digits string) []string {

	f:=map[byte]string{
		'2':"abc",
		'3':"def",
		'4':"ghi",
		'5':"jkl",
		'6':"mno",
		'7':"pqrs",
		'8':"tuv",
		'9':"wxyz",
	}

	n:=len(digits)
	diary:=""
	res:=[]string{}

	if n==0{
		return res
	}

	var fun func(string,int,int,*string,[]string) []string

	fun=func(digits string,n int,idx int,diary *string,res []string) []string{

		// Last wla stage lelo
		if idx==n{
			res=append(res,*diary)
			return res
		}

		// Strings ko button ke nichey hai sab ek sath nilega
		choice:=f[digits[idx]]

		for j:=0;j<len(choice);j++{

			// Push kardo har j k index ko
			*diary+=string(choice[j])

			// Explore karlo next wley mei jakey
			res=fun(digits,n,idx+1,diary,res)

			// Reverse kardo
			*diary=(*diary)[:len(*diary)-1]
		}

		return res
	}

	// Recursive Call kardo intio main
	res=fun(digits,n,0,&diary,res)

	return res
}