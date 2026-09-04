class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=4;                        // atmost 2 hai so 4 no. of transactions as combo(buy-sell typos)
        // 2D Array(matrix)of size n+1*k+1 bna lo 
        vector<vector<int>>dp(n+1,vector<int>(k+1));
        // Base case: jab hum last din mei agye hai 
        for(int j=0;j<=k;j++){
            dp[n][j]=0;                     // Nth row ko 0 se hi fill kardo completely 
        }
        // Agar no. of the Transactions hi 0 hogye 
        for(int i=0;i<=n;i++){
            dp[i][0]=0;                  // if k==0 hogya then return 0 hoga toh fill that too 
        }
        // Ab Reverse order mein fill krna hai 
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                if(j%2==0){
                    // Jab even hua: Toh Buy wla case banega 
                    int c1=dp[i+1][j-1]-prices[i];                    // Buy kardia 
                    int c2=dp[i+1][j];                                // Simply agey badho without buying
                    dp[i][j]=max(c1,c2);
                }
                else{
                    // Odd hi hoga :Toh ell wla Case banega 
                    int c1=dp[i+1][j-1]+prices[i];                   // Sell kardia 
                    int c2=dp[i+1][j];                               // Simply agey badho without selling 
                    dp[i][j]=max(c1,c2);
                }
            }
        }
        return dp[0][k];                                            // Max Profit return kardo 
    }
};