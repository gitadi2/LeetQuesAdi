// By DP Method
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        int mod=1e9+7;

        // dp[i] = first i characters se banne wali distinct subsequences
        vector<long long>dp(n+1,0);

        // Empty subsequence ko bhi count karenge
        dp[0]=1;

        // Har character ko process karo
        vector<long long>last(26,0);

        for(int i=1;i<=n;i++){
            int c=s[i-1]-'a';

            // Current character ko add karke naye subsequences banao
            dp[i]=(2*dp[i-1])%mod;

            // Agar current character pehle aa chuka hai
            // toh duplicate subsequences remove karo
            dp[i]=(dp[i]-last[c]+mod)%mod;

            // Is character ke liye current dp value store karo
            last[c]=dp[i-1];
        }
        // Empty subsequence ko answer se remove karo
        return (dp[n]-1+mod)%mod;
    }
};