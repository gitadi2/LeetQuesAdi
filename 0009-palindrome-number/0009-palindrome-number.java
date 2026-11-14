// Brute Force (String + Two Pointers)

class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        String s=String.valueOf(x);
        int n=s.length();

        int i=0;
        int j=n-1;

        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}