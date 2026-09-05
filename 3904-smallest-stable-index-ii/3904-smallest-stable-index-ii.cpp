// By Prefix Max + Suffix Min Method
class Solution {
public:
    int firstStableIndex(vector<int>&nums,int k){
        int n=nums.size();

        // Suffix Minimum array bna lo
        vector<int>right(n);
        right[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            right[i]=min(right[i+1],nums[i]);
        }

        // Prefix maximum ko maintain karenge
        int left=0;

        for(int i=0;i<n;i++){
            left=max(left,nums[i]);
            // instability score=prefix max-suffix min
            if(left-right[i]<=k){
                return i;                            // smallest stable index mil gaya
            }
        }
        // Koi stable index nahi mila
        return -1;
    }
};