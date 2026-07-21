class Solution {
public:
    bool fun(string& s,int low,int high){

        // non-alphanumeric characters ko skip karo
        while(low<high && !isalnum(s[low])){
            low++;
        }

        while(low<high && !isalnum(s[high])){
            high--;
        }

        // Base Case
        if(low>=high){
            return true;
        }

        // agar first aur last character equal nahi hai
        if(tolower(s[low])!=tolower(s[high])){
            return false;
        }

        // Recursive Call nxt walo k liye
        return fun(s,low+1,high-1);
    }

    bool isPalindrome(string s){

        // Size of the String
        int n=s.size();

        int low=0;
        int high=n-1;

        // Recursive Fn. call kardo
        return fun(s,low,high);
    }
};