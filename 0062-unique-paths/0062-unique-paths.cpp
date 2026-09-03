// By the Tabulation method in DP 

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1));         // 2D Array(Matrix) bna Lo of the size n*m

        // Base Case lelo: Jab Target tak reach hojaega 
        dp[n-1][m-1]=1;                                 // Count 1 hojaega 
        // Ab invalid wley dekhlo 
        for(int j=0;j<=m;j++){
            dp[n][j]=0;                  // Nth row ko 0 se fill kardo 
        }
        for(int i=0;i<=n;i++){
            dp[i][m]=0;                   // Mth Column ko pura 0 se bhar do 
        }

        // Ab baki ko bharna hai 
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    continue;             // Agar i and j last mei reach kar gya toh skip and continue kardo
                }
                dp[i][j]=dp[i+1][j]+dp[i][j+1];         // Ek chance mei row ko badha and next mei col ko 
            }
        }
        return dp[0][0];                    // Final Ans 
    }
};