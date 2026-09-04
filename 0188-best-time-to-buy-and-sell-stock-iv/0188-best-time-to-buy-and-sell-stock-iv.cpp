// By the Recursive Method in DP

class Solution {
public:
int fun(vector<int>&prices,int n,int i,int k,vector<vector<int>>&dp){
    // base Case: jab last din mein reach kar gye 
    if(i==n){
        return 0;
    }
    // Agar no. of trans hai hi nhi 
    if(k==0){
        return 0;
    }
    // Agar pheley se dp k matrix mei hai val toh return kardo 
    if(dp[i][k]!=-1){
        // Yni ki present hai 
        return dp[i][k];
    }
    if(k%2==0){
        // agr Even hai: Toh Buy ka Case banado 
        int c1=fun(prices,n,i+1,k-1,dp)-prices[i];            // Buy kardia 
        int c2=fun(prices,n,i+1,k,dp);                        // Simply move fwd without Buying 
        return dp[i][k]=max(c1,c2);
    }
    else{
        // Agar Odd hai: Toh Sell wla Case banega 
        int c1=fun(prices,n,i+1,k-1,dp)+prices[i];           // Sell kardia 
        int c2=fun(prices,n,i+1,k,dp);                       // Simply move fwd without selling 
        return dp[i][k]=max(c1,c2);
    }
}

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int transactions=k*2;                                         // Atmost k Times hai 
        // 2D array(matrix) of DP bna lo of size n+1*k+1
        vector<vector<int>>dp(n+1,vector<int>(transactions+1,-1));
        int profit=fun(prices,n,0,transactions,dp);                    // Recursive Function call kardo 
        return profit;
    }
};