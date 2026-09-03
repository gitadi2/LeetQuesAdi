// By Tabulation Methon in DP

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2;                           // No. of Transactions 2 hi hai
        //2D arry(matrix) bna lo of the size n+1*k+1
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

        // Base Case: Agar last row tak pahunch gye, toh zero se fill kardo
        for(int j=0;j<=k;j++){
            dp[n][j]=0;                    // Nth Row ko pura Zero hi kardo
        }
        // Agar k==0 hai : Yni ki transaction ab kch hai hi nhi
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }

        // Ab bakki sabko Reverse Order mein fill karna hai
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                if(j==2){
                    // Buy wla Case hua
                    int c1=dp[i+1][j-1]-prices[i];         // Buy karlia
                    int c2=dp[i+1][j];                     // Simply agey badhey without buying
                    dp[i][j]=max(c1,c2);
                }
                else if(j==1){
                    // Toh Sell karney ka Case hai
                    int c1=dp[i+1][j-1]+prices[i];         // Sell kardia hai
                    int c2=dp[i+1][j];                     // Simply agey badho without selling
                    dp[i][j]=max(c1,c2);
                }
            }
        }
        return dp[0][2];                               // Final Max Profit
    }
};