// By Tabulatiuon Method in DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        // 2D Array (Matrix) of Size n+1*m+1 bna lo 
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        
        // Base Case bna Lo: Nth Row and Mth col fill kardo with 0
        for(int i=0;i<n;i++){
            dp[i][m]=0;           // Mth col ko 0 se bhar do 
        }        
        for(int j=0;j<m;j++){
            dp[n][j]=0;          // Nth Row ko 0 se bhar do 
        }

        // Ab baki ko bharna shuru karna hai but in reverse order 
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                // agr char math hogye in both strings 
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];                // LCS ko 1 karkey dono mein agey badh jao 
                }
                else{
                    // agar esa nhi hota hai 
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);        // Pheley i ko bda do and fir j ko max lelo 
                }
            }
        }
        return dp[0][0];                                // Final Length of LCS dega 
    }
};