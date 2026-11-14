// Sliding Window (Fixed Sliding Window)

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int res=INT_MAX;

        for(int len=l;len<=r;len++){
            int sum=0;
            // Calculate initial window sum
            for(int i=0;i<len;i++){
                sum+=nums[i];
            }
            if(sum>0){
                res=min(res,sum);
            }

            // Slide the window
            for(int i=len;i<n;i++){
                sum+=nums[i];
                sum-=nums[i-len];

                if(sum>0){
                    res=min(res,sum);
                }
            }
            if(res==1){
                return 1;
            }
        }
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};