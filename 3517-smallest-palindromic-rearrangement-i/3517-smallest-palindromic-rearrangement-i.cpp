class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int>cnt(26,0);          // Har character ki frequency store karlo

        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }

        string left="";
        char mid=0;

        for(int i=0;i<26;i++){

            // Half characters ko left part mei daal do
            for(int j=0;j<cnt[i]/2;j++){
                left.push_back(char(i+'a'));
            }

            // Odd frequency wla character middle mei aayega
            if(cnt[i]%2==1){
                mid=char(i+'a');
            }
        }

        string right=left;
        reverse(right.begin(),right.end());

        // Agar middle character nhi hai
        if(mid==0){
            return left+right;
        }
        return left+string(1,mid)+right;
    }
};