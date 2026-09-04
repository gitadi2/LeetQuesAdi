// By Prefix Max + Suffix Min Method

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        // Right wala Array bna lo : Suffix Minimum store karega
        vector<int>right(n);
        // Base Case: Last element ka suffix minimum woh khud hi hoga
        right[n-1]=nums[n-1];
        // Right Array ko reverse order mei bhar do
        for(int i=n-2;i>=0;i--){
            right[i]=min(right[i+1],nums[i]);
        }
        // Prefix Maximum maintain karne ke liye
        int left=0;
        // Sabhi indexes ko check karo
        for(int i=0;i<n;i++){
            // Prefix Maximum update karo
            left=max(left,nums[i]);
            // Agar Instability Score valid hai
            if(left-right[i]<=k){
                return i;
            }
        }
        // Agar koi Stable Index nhi mila
        return -1;
    }
};