// By Palindrome DP + Tabulation Method

class Solution {
public:
    int maxPalindromes(string s,int k) {
        int n=s.size();

        // dp[i][j] = check karo ki s[i...j] palindrome hai ya nahi
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        // Single character hamesha palindrome hota hai
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }

        // Length 2 se n tak substring check karo
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;

                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
            }
        }
        // ans[i] = first i characters mein max palindromes
        vector<int>ans(n+1,0);

        for(int i=1;i<=n;i++){
            // Current character ko skip karo
            ans[i]=ans[i-1];
            // Minimum length k ka palindrome check karo
            for(int j=0;j<=i-k;j++){
                if(dp[j][i-1]){
                    ans[i]=max(ans[i],ans[j]+1);
                }
            }
        }
        return ans[n];
    }
};