public class Solution {
    public bool CheckDivisibility(int n) {
        int sum=0;
        int product=1;
        int x=n;

        // Har digit ko nikalenge
        while(x!=0){
            int digit=x%10;
            x/=10;
            sum+=digit;
            product*=digit;
        }
        // Divisibility check
        return n%(sum+product)==0;
    }
}