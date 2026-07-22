class Solution {
public:
void fun(int open, int close,int n,string&tmp,vector<string>&res){
    if(open==n && close==n){
        // Jab Limit wla hit hojae 
        res.push_back(tmp);
        return;
    }

    // Open wla Parenthesis k liye 
    if(open<n){
        tmp.push_back('(');
        fun(open+1,close,n,tmp,res);
        tmp.pop_back();
    }

    // Close Wala Parenthesis lelo 
    if(close<open){
        tmp.push_back(')');
        fun(open, close+1,n,tmp,res);
        tmp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;    //Resultant wla array lwelo
        string tmp="";
        
        // Recursive Function Call kardo 
        fun(0,0,n,tmp,res);

        return res;
    }
};