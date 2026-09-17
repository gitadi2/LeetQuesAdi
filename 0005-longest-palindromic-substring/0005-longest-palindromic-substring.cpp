// By Brute Force Approach

class Solution {
public:
    bool fun(string&s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                // Agar equal hai hi nhi
                return false;
            }
            // Agar equal hai ya nhi bhi hai agey toh badhega hii
            l++;
            r--;
        }
        // Pura check hone ke baad palindrome hai
        return true;
    }

    string longestPalindrome(string s) {
        int n=s.size();
        string res="";         // Resultant String shuru mein khali lelo

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                if(fun(s,i,j)){
                    // Agar y hold hua yani palindrome hai string

                    if(j-i+1>res.size()){
                        // Check karo ki current substring ki length
                        // res se badi hai toh longest hai

                        res=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return res;            // Longest substring return kardo
    }
};