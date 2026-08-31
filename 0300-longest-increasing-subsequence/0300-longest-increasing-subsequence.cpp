// By the Tabulation Method of DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // 2D Array(Matrix) of the size n+1*n+1 bna lo 
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        // Base Case: Nth Row of the Dp Matrix bhar lo 
        for(int j=0;j<=n;j++){
            dp[n][j]=0;                 // Pura Nth Row 0 se bhar do 
        }
        // Ab pheley k Rows Bharo 
        for(int i=n-1;i>=0;i--){
            for(int prevEle=-1;prevEle<=i-1;prevEle++){
                // Agar PrevEle kuch nhi hai ya fir PrevEle chota hai than curr element
                if(prevEle==-1 || nums[prevEle]<nums[i]){
                    // 2 Choice banega uska max lelo 
                    dp[i][prevEle+1]=max(1+dp[i+1][i+1],dp[i+1][prevEle+1]);
                }
                // Agar esa hi hai
                else{
                    dp[i][prevEle+1]=dp[i+1][prevEle+1];          // Ek hi choice hai as No toh agey badhado
                }
            }
        }
        return dp[0][0];                // Final ans return kardo
    }
};