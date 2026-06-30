class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();

        unordered_map<char,int>mp;         // Hashmap Dec. for the char and freq storage
        for(int i=0;i<n;i++){
            mp[s[i]]++;                    // Append onto the hashmap
        }

        bool odd=false;                    // odd freq is not taken for a duration (assumption)
        int res=0;                         // Result
        for(auto i:mp){
            int val=i.second;
            if(val%2==0){
                // If the even freq. comes
                res+=val;
            }
            else{
                odd=true;
            }
        }
        // Odd No. of times is not at all present only
        if(odd==false){
            return res;
        }

        for(auto i:mp){
            int val=i.second;
            if(val%2==1){
                // If the Odd Freq comes
                res+=val-1;             // break into pairs; take the pairs and leave the single ones
            }
        }
        return res+1;                   // Take any of the char left and add 1 as the length increases
    }
};