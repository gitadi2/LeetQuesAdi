class Solution {
    boolean fun(String s,int low,int high){

        // non-alphanumeric characters ko skip karo
        while(low<high && !Character.isLetterOrDigit(s.charAt(low))){
            low++;
        }

        while(low<high && !Character.isLetterOrDigit(s.charAt(high))){
            high--;
        }

        // Base Case
        if(low>=high){
            return true;
        }

        // agar first aur last character equal nahi hai
        if(Character.toLowerCase(s.charAt(low))!=Character.toLowerCase(s.charAt(high))){
            return false;
        }

        // Recursive Call nxt walo k liye
        return fun(s,low+1,high-1);
    }

    public boolean isPalindrome(String s){

        // Size of the String
        int n=s.length();

        int low=0;
        int high=n-1;

        // Recursive Fn. call kardo
        return fun(s,low,high);
    }
}