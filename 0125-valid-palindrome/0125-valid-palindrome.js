/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome=function(s){
    function fun(s,low,high){

        // non-alphanumeric characters ko skip karo
        while(low<high && !/[a-zA-Z0-9]/.test(s[low])){
            low++;
        }

        while(low<high && !/[a-zA-Z0-9]/.test(s[high])){
            high--;
        }

        // Base Case
        if(low>=high){
            return true;
        }

        // agar first aur last character equal nahi hai
        if(s[low].toLowerCase()!=s[high].toLowerCase()){
            return false;
        }

        // Recursive Call nxt walo k liye
        return fun(s,low+1,high-1);
    }

    // Size of the String
    let n=s.length;

    let low=0;
    let high=n-1;

    // Recursive Fn. call kardo
    return fun(s,low,high);
};