class Solution {
public:
    int stoneGameVIII(vector<int>&stones) {

        int n=stones.size();

        // Prefix Sum bna lo
        vector<int>sum(n);

        sum[0]=stones[0];

        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+stones[i];
        }

        // Last state se shuru karo
        int res=sum[n-1];

        // Right se left DP
        for(int i=n-2;i>=1;i--){

            // Maximum score difference
            res=max(res,sum[i]-res);
        }

        return res;
    }
};