class Solution {

    public void fun(int open,int close,int n,StringBuilder tmp,List<String> res){

        if(open==n && close==n){
            // Jab Limit wla hit hojae
            res.add(tmp.toString());
            return;
        }

        // Open wla Parenthesis k liye
        if(open<n){
            tmp.append('(');
            fun(open+1,close,n,tmp,res);
            tmp.deleteCharAt(tmp.length()-1);
        }

        // Close Wala Parenthesis lelo
        if(close<open){
            tmp.append(')');
            fun(open,close+1,n,tmp,res);
            tmp.deleteCharAt(tmp.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {

        List<String> res=new ArrayList<>();
        StringBuilder tmp=new StringBuilder();

        // Recursive Function Call kardo
        fun(0,0,n,tmp,res);

        return res;
    }
}