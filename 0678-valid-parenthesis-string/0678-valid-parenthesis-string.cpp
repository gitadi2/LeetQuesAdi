// Tabulation Approach

class Solution {
public:
    bool checkValidString(string s){
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        // Base case
        dp[n][0]=1;

        for(int ind=n-1;ind>=0;ind--){
            for(int cnt=0;cnt<=n;cnt++){
                // Agar Opening Parenthesis mila '('
                if(s[ind]=='('){
                    if(cnt+1<=n){
                        dp[ind][cnt]=dp[ind+1][cnt+1];
                    }
                }

                // Agar Closing hua toh ')'
                else if(s[ind]==')'){
                    if(cnt>0){
                        dp[ind][cnt]=dp[ind+1][cnt-1];
                    }
                }

                // Agar Asterick '*' mila toh
                else if(s[ind]=='*'){
                    // '*' ko '(' maan lo
                    bool c1=false;
                    if(cnt+1<=n){
                        c1=dp[ind+1][cnt+1];
                    }

                    // '*' ko ')' maan lo
                    bool c2=false;
                    if(cnt>0){
                        c2=dp[ind+1][cnt-1];
                    }

                    // '*' ko empty maan lo
                    bool c3=dp[ind+1][cnt];
                    dp[ind][cnt]=c1||c2||c3;
                }
            }
        }
        return dp[0][0];
    }
};