class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int cnt=0;
        int len=INT_MAX;

        string res="";

        while(j<n){
            // Agar current character 1 hai
            if(s[j]=='1'){
                cnt++;
            }

            // Jab exactly k ones ho gaye
            while(cnt==k){
                // Current substring valid tabhi hoga jab first character bhi 1 ho
                while(i<=j && s[i]=='0'){
                    i++;
                }

                int currLen=j-i+1;

                // Shorter substring mil gaya
                if(currLen<len){
                    len=currLen;
                    res=s.substr(i,currLen);
                }
                // Same length hai toh lexicographically smaller check karo
                else if(currLen==len){
                    string temp=s.substr(i,currLen);
                    if(temp<res){
                        res=temp;
                    }
                }
                // Left se 1 remove karo
                if(s[i]=='1'){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};