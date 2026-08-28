class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n=nums.size();

        // Total Sum nikal lo
        int total=0;

        for(int i=0;i<n;i++){
            total+=nums[i];
        }

        // Agar Total Sum Odd hai Toh Equal Partition possible nhi hai
        if(total%2!=0){
            return false;
        }
        // Equal partition ke liye required sum
        int sum=total/2;

        // 2D Array Bna Lo
        vector<vector<int>>dp(n+1,vector<int>(sum+1));

        // Base Case : Nth Row ko fill karo
        for(int j=1;j<=sum;j++){
            // Agar elements khatam ho gaye and sum non-zero hai
            dp[n][j]=0;
        }

        // Sum 0 hamesha possible hai
        dp[n][0]=1;

        // Ab DP Array ko bharna shuru karo
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=sum;j++){
                if(nums[i]>j){
                    // Agar Current Element current sum se jyada hai toh simply agey badho
                    dp[i][j]=dp[i+1][j];
                }
                else{
                    // Current element lo andCurrent element mat lo
                    dp[i][j]=(dp[i+1][j-nums[i]]) || (dp[i+1][j]);
                }
            }
        }
        // Kya sum/2 ka subset ban sakta hai?
        return dp[0][sum];
    }
};