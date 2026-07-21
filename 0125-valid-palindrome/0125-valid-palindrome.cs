public class Solution {

    bool Fun(string s,int low,int high){

        // non-alphanumeric characters ko skip karo
        while(low<high && !char.IsLetterOrDigit(s[low])){
            low++;
        }

        while(low<high && !char.IsLetterOrDigit(s[high])){
            high--;
        }

        // Base Case
        if(low>=high){
            return true;
        }

        // agar first aur last character equal nahi hai
        if(char.ToLower(s[low])!=char.ToLower(s[high])){
            return false;
        }

        // Recursive Call nxt walo k liye
        return Fun(s,low+1,high-1);
    }

    public bool IsPalindrome(string s){

        // Size of the String
        int n=s.Length;

        int low=0;
        int high=n-1;

        // Recursive Fn. call kardo
        return Fun(s,low,high);
    }
}