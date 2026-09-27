class Solution {
public:
    string reverseParentheses(string s){
        int n=s.size();

        stack<string>st;
        string curr="";

        // String ko traverse karo
        for(int i=0;i<n;i++){
            // Agar opening bracket '(' mila
            if(s[i]=='('){
                st.push(curr);
                curr="";
            }
            // Agar closing bracket ')' mila
            else if(s[i]==')'){
                // Current string ko reverse karo
                reverse(curr.begin(),curr.end());

                // Previous string ke saath combine karo
                curr=st.top()+curr;
                st.pop();
            }
            // Normal character hai
            else{
                curr+=s[i];
            }
        }
        return curr;
    }
};