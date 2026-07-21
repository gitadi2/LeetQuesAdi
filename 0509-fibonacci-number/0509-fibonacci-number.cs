public class Solution {
    public int Fib(int n) {
        // base Case 
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        // Recursive call kardo 
        int ans= Fib(n-1)+Fib(n-2);

        return ans;
        
    }
}