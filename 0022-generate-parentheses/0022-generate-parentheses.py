class Solution:

    def fun(self,open,close,n,tmp,res):

        if open==n and close==n:
            # Jab Limit wla hit hojae
            res.append("".join(tmp))
            return

        # Open wla Parenthesis k liye
        if open<n:
            tmp.append('(')
            self.fun(open+1,close,n,tmp,res)
            tmp.pop()

        # Close Wala Parenthesis lelo
        if close<open:
            tmp.append(')')
            self.fun(open,close+1,n,tmp,res)
            tmp.pop()

    def generateParenthesis(self,n):

        res=[]
        tmp=[]

        # Recursive Function Call kardo
        self.fun(0,0,n,tmp,res)

        return res