class Solution {
public:
    bool checkDivisibility(int n) {
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
        // n ko digit sum + digit product se divide karo
        return n%(sum+product)==0;
    }
};