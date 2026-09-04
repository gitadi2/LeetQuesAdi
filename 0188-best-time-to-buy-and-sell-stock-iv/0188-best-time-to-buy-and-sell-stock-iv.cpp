// By the Tabulation Method in the DP

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int transactions=k*2;                        // Atmost k No. of the Transactions hai 
        // 2D array(matrix) of Dp bna lo of size n+1*tarnsactions+1
        vector<vector<int>>dp(n+1,vector<int>(transactions+1));

        // Base Case : Jab last Din mein reach hojae 
        for(int j=0;j<=transactions;j++){
            dp[n][j]=0;                             // Nth Row ko comopletely 0 se fill kardo 
        }
        // Agar kuch trans ho hi nhi rha hai 
        for(int i=0;i<=n;i++){
            dp[i][0]=0;                            
        }
        // Ab Reverse order mein bharna shuru kardo 
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=transactions;j++){
                // Buy wla case banega 
                if(j%2==0){
                    int c1=dp[i+1][j-1]-prices[i];                   // Buy karlia 
                    int c2=dp[i+1][j];                               // agey badho without buying 
                    dp[i][j]=max(c1,c2);
                }
                else{
                    // Agar Odd wla hai, toh sell banega : if(j%2!=0)
                    int c1=dp[i+1][j-1]+prices[i];                   // Sell kardia 
                    int c2=dp[i+1][j];                               // Agey badho without selling 
                    dp[i][j]=max(c1,c2);
                }
            }
        }
        return dp[0][transactions];                              // Final Max. Profit return kardo 
    }
};