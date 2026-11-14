// Optimal (Reverse Half of the Number)

class Solution {
    public boolean isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }
        int rev=0;

        while(x>rev){
            int rem=x%10;
            rev=rev*10+rem;
            x=x/10;
        }
        if(x==rev || x==rev/10){
            return true;
        }
        return false;
    }
}