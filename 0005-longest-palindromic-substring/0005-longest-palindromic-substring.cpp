// By Two Pointer Approach (MOST OPTIMIZED APPROACH)

class Solution {
public:
    void fun(string&s,int l,int r,int&start,int&maxLen){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            // Current palindrome ki length
            int len=r-l+1;
            // Agar current palindrome longest hai
            if(len>maxLen){
                start=l;
                maxLen=len;
            }
            // Dono pointers ko expand karo
            l--;
            r++;
        }
    }

    string longestPalindrome(string s){
        int n=s.size();

        int start=0;             // Longest palindrome ka starting index
        int maxLen=1;            // Initially ek character palindrome hai

        for(int i=0;i<n;i++){
            // Odd length palindrome ke liye
            fun(s,i,i,start,maxLen);
            // Even length palindrome ke liye
            fun(s,i,i+1,start,maxLen);
        }
        return s.substr(start,maxLen);
    }
};