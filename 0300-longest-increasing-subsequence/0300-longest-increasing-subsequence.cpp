// LIS using Memoization Method in DP
class Solution {
public:
int fun(vector<int>&nums,int n,int i,int prevEle,vector<vector<int>>&dp){
    // Base case: jab hum last element par reach kar gye in array 
    if(i==n){
        return 0;
    }
    // Agar DP wley matrix mein pheley se hi hai 
    if(dp[i][prevEle+1]!=-1){
        return dp[i][prevEle+1];
    }

    if(prevEle==-1 || nums[prevEle]<nums[i]){
        // Agar prev element kuch hai hi nhi ya fir prev elemnt current element se chota hai , toh 2 choices
        int yes=1+fun(nums,n,i+1,i,dp);       // Agar humney lia 
        int no=fun(nums,n,i+1,prevEle,dp);     // Agar humney nhi lia 

        return dp[i][prevEle+1]=max(yes,no);                // Max Ans from both seen paths dekhlo 
    }
    // Agar prevEle hai kch bhi and woh bda hai curr ele se , toh nhi hi lengey 
    return dp[i][prevEle+1]=fun(nums,n,i+1,prevEle,dp);
}

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        // 2D arry(matrix) bna lo of size n+1*n+1
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // Recursive Function Call kardo 
        return fun(nums,n,0,-1,dp);
    }
};