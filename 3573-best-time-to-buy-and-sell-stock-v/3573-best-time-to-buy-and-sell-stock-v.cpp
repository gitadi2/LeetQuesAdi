// By the Tabulation Method in DP

class Solution {
public:
    long long maximumProfit(vector<int>&prices,int k){
        int n=prices.size();
        // 3 states: 0 = Nothing, 1 = Buy, 2 = Short
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        // Base Case: jab last din mein reach hojae
        for(int j=0;j<=k;j++){
            dp[n][j][0]=0;                 // Koi transaction open nhi hai
            dp[n][j][1]=LLONG_MIN/2;       // Transaction open hai toh complete nhi hui
            dp[n][j][2]=LLONG_MIN/2;       // Transaction open hai toh complete nhi hui
        }
        // Ab Reverse order mein fill karna shuru karo
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=k;j++){
                // Nothing wala Case
                long long c1=dp[i+1][j][0];                         // Kch nhi kia
                long long c2=dp[i+1][j][1]-prices[i];              // Buy kardia
                long long c3=dp[i+1][j][2]+prices[i];              // Short sell kardia
                dp[i][j][0]=max(c1,max(c2,c3));

                // Normal transaction: Buy karke hold kar rahe hain
                c1=dp[i+1][j][1];                                  // Hold karo
                c2=LLONG_MIN/2;
                if(j>0){
                    c2=dp[i+1][j-1][0]+prices[i];                  // Sell karke transaction complete
                }
                dp[i][j][1]=max(c1,c2);

                // Short transaction: Sell karke hold kar rahe hain
                c1=dp[i+1][j][2];                                  // Hold karo
                c2=LLONG_MIN/2;
                if(j>0){
                    c2=dp[i+1][j-1][0]-prices[i];                  // Buy back karke transaction complete
                }
                dp[i][j][2]=max(c1,c2);
            }
        }
        return dp[0][k][0];
    }
};