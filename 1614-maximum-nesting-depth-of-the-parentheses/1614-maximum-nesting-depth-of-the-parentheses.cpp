class Solution {
public:
    int maxDepth(string s){
        int n=s.size();

        int curr=0;
        int res=0;

        // String ko traverse karo
        for(int i=0;i<n;i++){
            // Agar opening bracket '(' mila
            if(s[i]=='('){
                curr++;
                // Maximum depth update karo
                res=max(res,curr);
            }
            // Agar closing bracket ')' mila
            else if(s[i]==')'){
                curr--;
            }
        }
        return res;
    }
};