class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;              // Dec of total sum of the array lelo 

        // Total Sum nikal lo 
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }

        // Agar Target possible hi nhi hai 
        if(abs(target)>totalSum){
            return 0;
        }
        // Agar possible hai 
        if((totalSum+target)%2!=0){
            // Agar Odd hai total sum toh partition nhi ho skta 
            return 0;
        }
        // Agar even hai toh ho skta hai partition
        int sum=(totalSum+target)/2;

        // 2D Array(Matrix) of the DP bna lo 
        vector<vector<int>>dp(n+1,vector<int>(sum+1));           // matrix of n+1*sum+1

        // Base Case: Nth Row with 0 as empty subset sum bhardo 
        dp[n][0]=1;

        // DP Array bhar lo 
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=sum;j++){

                // Agar Curr wla ele sum se hi bda hai 
                if(nums[i]>j){
                    dp[i][j]=dp[i+1][j];         // Simply agey badh jao 
                }
                else{
                    // Agar esa nhi hai 
                    dp[i][j]=dp[i+1][j-nums[i]]+dp[i+1][j];  
                }
            }
        }
        return dp[0][sum];           // Ye Final Ans banega 
    }
};