// By tabulation Method in DP

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int k=2;                               // Unlimited Choices of buy-sell types hai tabhi init karo

      // 2D Array(Matrix ) bna Lo of the Size n+1*k+1
      vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

      // Base Case: jab last wley din mein reach hojae hum
      for(int j=0;j<=k;j++){
        dp[n][j]=0;                         // yani ki Nth row ko pura hi 0 se bhardo
      }
      // ab Reverse Order mei filling karna shuru kro
      for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            if(j==2){
                // Buy wla Case hai 
                int c1=dp[i+1][1]-prices[i];            // Buy karlia 
                int c2=dp[i+1][2];                     // Simply move fwd without buying 
                dp[i][j]=max(c1,c2);
            }
            else if(j==1){
                // Selling wla case hai 
                int c1=dp[i+1][2]+prices[i];               // Sell kro and 1 karo trans ko for unlimited
                int c2=dp[i+1][1];                         // Simply agey badh jao witout selling
                dp[i][j]=max(c1,c2);
            }
        }
      }
      return dp[0][2];                                    // Final Max Profit yhi hoga 
    }
};