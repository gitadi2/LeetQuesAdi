class Solution:
    def fun(self,s,low,high):

        # non-alphanumeric characters ko skip karo
        while low<high and not s[low].isalnum():
            low+=1

        while low<high and not s[high].isalnum():
            high-=1

        # Base Case
        if low>=high:
            return True

        # agar first aur last character equal nahi hai
        if s[low].lower()!=s[high].lower():
            return False

        # Recursive Call nxt walo k liye
        return self.fun(s,low+1,high-1)

    def isPalindrome(self,s):

        # Size of the String
        n=len(s)

        low=0
        high=n-1

        # Recursive Fn. call kardo
        return self.fun(s,low,high)