// By the Memoization Method in DP

class Solution {
public:
int fun(vector<int>&prices,int n,int i,int k,vector<vector<int>>&dp){
    // Base case lelo: jab hum last din par reach kar gye 
    if(i==n){
        return 0;
    }
    // Agar Trans k no. 0 hogya 
    if(k==0){
        return 0;
    }
    // Ab Dekhlo ki Dp Array mein hai ki nhi 
    if(dp[i][k]!=-1){
        // yani ki present hai 
        return dp[i][k];
    }
    // Ab buy wla case 
    if(k%2==0){
        // Even hai ; toh buy wla case hai 
        int c1=fun(prices,n,i+1,k-1,dp)-prices[i];              // Buy Kardia 
        int c2=fun(prices,n,i+1,k,dp);                          // Kch nhi kia without buying 
        return dp[i][k]=max(c1,c2);
    }
    else{
        // Yani ki odd hai: Toh Sell wla case banega 
        int c1=fun(prices,n,i+1,k-1,dp)+prices[i];               // Sell kardia 
        int c2=fun(prices,n,i+1,k,dp);                            // Simpply agey badha without selling 
        return dp[i][k]=max(c1,c2);
    }
}

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=4;                                       // Atmost 2 hai toh 4 hojaega 
        // 2D arry (Matrix) of DP bna lo of size n+1*k+1
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int profit=fun(prices,n,0,k,dp);                // Recursivce function call kardo
        return profit;                                  // Max Profit return kardo as answer
    }
};