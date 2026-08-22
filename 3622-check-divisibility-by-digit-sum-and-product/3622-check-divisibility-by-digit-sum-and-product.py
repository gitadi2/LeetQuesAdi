class Solution:
    def checkDivisibility(self,n:int)->bool:
        sum=0
        product=1
        x=n

        # Har digit ko nikalenge
        while x!=0:
            digit=x%10
            x//=10
            sum+=digit
            product*=digit

        # Divisibility check
        return n%(sum+product)==0