// By DP + Modulo Method

class Solution {
public:
    vector<long long> resultArray(vector<int>&nums,int k) {
        int n=nums.size();
        // ans[i] = product ka remainder i hone wale total subarrays ki count
        vector<long long>ans(k,0);

        // dp[i] = current position par end hone wale subarrays jinka product ka remainder i hai
        vector<long long>dp(k,0);

        for(int i=0;i<n;i++){
            int rem=nums[i]%k;
            // Current element se naye subarrays banenge
            vector<long long>next(k,0);
            // Sirf current element wala subarray
            next[rem]=1;
            // Purane subarrays ko current element ke saath extend karo
            for(int j=0;j<k;j++){
                if(dp[j]>0){
                    int newRem=(j*rem)%k;

                    next[newRem]+=dp[j];
                }
            }
            // Current position par banne wale saare subarrays ko answer mein add karo
            for(int j=0;j<k;j++){
                ans[j]+=next[j];
            }
            // Next iteration ke liye dp update karo
            dp=next;
        }
        return ans;
    }
};