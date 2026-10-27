class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;          // Sign true --mtlb positive 
        if(dividend>=0 && divisor<0) sign=false;  // -ve sign bn jaega 
        if(dividend<=0 && divisor>0) sign=false; // -ve sign hi banega 

        long long n=abs((long long)dividend);       
        long long d=abs((long long)divisor); 
        long long q=0;                 // Quotient k liye 

        while(n>=d){
            int cnt=0;           // No of divisors to be removed 
            while(n>=(d<<(cnt+1))){
                cnt++;          // greatest waley ko jodna rehena 
            }
            q+=(1LL<<cnt);         // ans mei 2 k pwr cnt ko jodtey jao 
            n-=(d<<cnt);          // Remove kartey jao sabsey greatest ko 
        }
        if(q>INT_MAX && sign==true) return INT_MAX;    // Overflow cndn
        if(q>2147483648LL && sign==false) return INT_MIN;     // Underflow condn

        return sign ? (int)q : (int)(-q);
    }
};