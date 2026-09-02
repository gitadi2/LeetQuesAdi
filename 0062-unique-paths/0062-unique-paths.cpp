// By The Memoization Method in the DP

class Solution {
public:
int fun(int i,int j,int n,int m,vector<vector<int>>&dp){
    // Base Case: Agar hum log Goal State mei hi reach kar gye 
    if(i==n-1 && j==m-1){
        return 1;                   // Toh 1 path toh hoga hi thats why return 1 
    }
    // Validity chk karlo ki robot grid k bahar na ja paye 
    if(i<0 || i>=n || j<0 || j>=m){
        // Agar y hua , yni Invalid Range mei agya hai robot 
        return 0;
    }
    // Agar Dp mein pheley se hi present hua 
    if(dp[i][j]!=-1){
        return dp[i][j];                // Agar Dp mein pheley se hi hua toh whi return hojaega 
    }

    // Agar Valid Range mei hi hai , and move right and downwards karta hai 
    return dp[i][j]=fun(i+1,j,n,m,dp)+fun(i,j+1,n,m,dp); // Right gya toh i ko badhao and downwards gya toh leftko
}

    int uniquePaths(int m, int n) {
        //2D array bna lo (Matrix) bna lo odf the Dp array 
        vector<vector<int>>dp(n,vector<int>(m,-1));

        // Recursive  function Call kardo 
        return fun(0,0,n,m,dp);      
    }
};