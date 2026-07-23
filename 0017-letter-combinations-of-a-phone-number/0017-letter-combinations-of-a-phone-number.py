class Solution:
    def fun(self,digits,n,idx,diary,res,f):

        # Last wla stage lelo
        if idx==n:
            res.append("".join(diary))      # res hi mein push back kardo diary wla
            return

        # Strings ko button ke nichey hai sab ek sath nilega
        choice=f[digits[idx]]

        for j in range(len(choice)):

            # Push kardo har j k index ko
            diary.append(choice[j])

            # Explore karlo next wley mei jakey
            self.fun(digits,n,idx+1,diary,res,f)

            # Reverse kardo
            diary.pop()

        return

    def letterCombinations(self,digits):
        f={}

        # HashMap dec kardo taki sab ek sath ajae(1-9 tak)
        f['2']="abc"
        f['3']="def"
        f['4']="ghi"
        f['5']="jkl"
        f['6']="mno"
        f['7']="pqrs"
        f['8']="tuv"
        f['9']="wxyz"

        n=len(digits)
        diary=[]               # shuru mein empty hi hoga
        res=[]                 # Result k liye

        if n==0:
            return res

        # Recursive Call kardo intio main
        self.fun(digits,n,0,diary,res,f)

        return res