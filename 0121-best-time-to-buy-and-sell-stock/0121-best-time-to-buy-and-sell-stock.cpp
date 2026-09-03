//By Memoization method in DP 

class Solution {
public:
int fun(vector<int>&prices,int n,int i,int k,vector<vector<int>>&dp){
    // Base Case bna Lo: Jab Last din mei pahunch gya and koi trans nhi ho 
    if(i==n){
        return 0;
    }
    if(k==0){
        return 0;
    }
    // Ab Dekhlo agar pheley se hi dp mei hua toh 
    if(dp[i][k]!=-1){
        // Yani ki DP mei mil gya 
        return dp[i][k];
    }
    // Ab Buy wla case lelo 
    if(k==2){
        int c1=fun(prices,n,i+1,k-1,dp)-prices[i];        // Buy karli toh ghatega hi 
        int c2=fun(prices,n,i+1,k,dp);                    // Kch nhi kia only agey badhgya 
        return dp[i][k]=max(c1,c2);
    }
    else{
        // agar k==1 : Yni ki Sell wla case banega 
        int c1=fun(prices,n,i+1,k-1,dp)+prices[i];         // Sell kardi toh badhega hi 
        int c2=fun(prices,n,i+1,k,dp);                     // Kch bhi nhi kia 
        return dp[i][k]=max(c1,c2);
    }
}

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2;                // No. of transactions likhdoo
        // 2D arry bna lo (matrix) of size n+1*k+1
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

        int profit=fun(prices,n,0,k,dp);           // Recursive Func call kardo 
        return profit;                             // Max Profit nikal do as ans 
    }
};