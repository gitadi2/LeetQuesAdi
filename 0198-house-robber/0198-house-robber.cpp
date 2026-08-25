class Solution {
public:
int fun(vector<int>&nums,int n,int i,bool free,vector<vector<int>>&dp){
    // base Case: Jab last ghar mein pahunch jayein 
    if(i==n){
        return 0;
    }
    // Agar Dp k 2d matrix mei ans hai 
    if(dp[i][free]!=-1){
        return dp[i][free];
    }
    if(free==0){
        // Toh agey badh jao and next wley ka free will 1 kardo 
        return dp[i][free]=fun(nums,n,i+1,1,dp);
    }
    // agar free 0 nhi hai toh 2 cases banega 
    int c1=nums[i]+fun(nums,n,i+1,0,dp);            // Agar Rob karhey toh y case 1 
    int c2=fun(nums,n,i+1,1,dp);                    // Agar Rob nhi Karhey hai y case 2 

    return dp[i][free]=max(c1,c2);                  // Max wla jo hoga whi final return kardo 
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        // matrix of DP bna Lo 
        vector<vector<int>>dp(n,vector<int>(2,-1));            // n*2 size ka Dp with -1 in every cell 

        // Recursive Function Call kardo 
        return fun(nums,n,0,1,dp);
    }
};