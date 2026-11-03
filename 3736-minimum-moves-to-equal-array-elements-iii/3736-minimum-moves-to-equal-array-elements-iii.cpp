// Greedy Approach

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();

        int maxi=INT_MIN;
        int sum=0;

        // Maximum element aur total sum find karo
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        // Total moves calculate karo
        int res=(maxi*n)-sum;

        return res;
    }
};