class Solution {
    public String reverseParentheses(String s){
        int n=s.length();

        Stack<String>st=new Stack<>();
        String curr="";

        // String ko traverse karo
        for(int i=0;i<n;i++){
            // Agar opening bracket '(' mila
            if(s.charAt(i)=='('){
                st.push(curr);
                curr="";
            }
            // Agar closing bracket ')' mila
            else if(s.charAt(i)==')'){
                // Current string ko reverse karo
                curr=new StringBuilder(curr).reverse().toString();

                // Previous string ke saath combine karo
                curr=st.pop()+curr;
            }
            // Normal character hai
            else{
                curr+=s.charAt(i);
            }
        }
        return curr;
    }
}