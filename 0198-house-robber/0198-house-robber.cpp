class Solution {
public:
    int rob(vector<int>&nums) {
        int n=nums.size();
        // Matrix of DP bna lo
        vector<vector<int>>dp(n+1,vector<int>(2));

        // Base Case: Jab last ghar mein pahunch jayein
        dp[n][0]=0;
        dp[n][1]=0;

        // n-1 se 0 tak fill karo
        for(int i=n-1;i>=0;i--){
            // Agar free==0 hai toh current house ko skip karna padega
            dp[i][0]=dp[i+1][1];

            // Agar free==1 hai, toh 2 cases banenge
           dp[i][1]=max(nums[i]+dp[i+1][0],dp[i+1][1]);
        }
        return dp[0][1];
    }
};