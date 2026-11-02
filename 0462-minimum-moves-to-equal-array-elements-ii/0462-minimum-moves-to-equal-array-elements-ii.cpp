// Sorting + Greedy Approach

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());      // Array ko sort karo
        int mid=nums[n/2];               // Median find karo

        int res=0;

        // Median ke saath difference calculate karo
        for(int i=0;i<n;i++){
            res+=abs(nums[i]-mid);
        }
        return res;
    }
};