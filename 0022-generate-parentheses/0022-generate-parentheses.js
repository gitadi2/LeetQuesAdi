/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis=function(n){

    let res=[];
    let tmp=[];

    function fun(open,close){

        if(open===n && close===n){
            // Jab Limit wla hit hojae
            res.push(tmp.join(""));
            return;
        }

        // Open wla Parenthesis k liye
        if(open<n){
            tmp.push('(');
            fun(open+1,close);
            tmp.pop();
        }

        // Close Wala Parenthesis lelo
        if(close<open){
            tmp.push(')');
            fun(open,close+1);
            tmp.pop();
        }
    }

    // Recursive Function Call kardo
    fun(0,0);

    return res;
};