// Greedy Approach

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();

        int mini=INT_MAX;

        // Minimum element find karo
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
        }

        int res=0;

        // Minimum ke saath difference calculate karo
        for(int i=0;i<n;i++){
            res+=nums[i]-mini;
        }
        return res;
    }
};