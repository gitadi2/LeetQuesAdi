class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;                    // Total commas ko 0 se start karo

        // Har 1000 ke power par ek naya comma add hota hai
        for(long long x=1000;x<=n;x*=1000){
            // x se n tak ke har number mein ye comma present hoga
            res+=n-x+1;
        }
        return res;
    }
};