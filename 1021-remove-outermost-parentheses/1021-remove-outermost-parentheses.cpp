class Solution {
public:
    string removeOuterParentheses(string s){
        int n=s.size();

        string res="";
        int cnt=0;

        for(int i=0;i<n;i++){
            // Agar '(' mila
            if(s[i]=='('){
                cnt++;
                // Outermost '(' ko skip karo
                if(cnt>1){
                    res+=s[i];
                }
            }

            // Agar ')' mila
            else{
                cnt--;
                // Outermost ')' ko skip karo
                if(cnt>0){
                    res+=s[i];
                }
            }
        }
        return res;
    }
};