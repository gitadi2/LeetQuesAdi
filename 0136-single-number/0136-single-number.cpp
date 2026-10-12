// Bitwise Optimal Approach 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xr=0;           
        // Traverse Through the Array as whole 
        for(int i=0;i<n;i++){
            xr=xr^nums[i];       // using xor clubbing
        }
        return xr;
    }
};