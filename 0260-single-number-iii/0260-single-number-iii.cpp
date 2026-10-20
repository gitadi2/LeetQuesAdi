// Optimized Bucket Concept Soln

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long xr=0;
        // Traverse the elements of the Array and XOR them up
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
        }
        int rightmost=(xr & (xr-1)) ^ xr;    // To isolate the rightmost set bit
        int b1=0;                             // Bucket 1
        int b2=0;                             // Bucket 2
        for(int i=0;i<n;i++) {
            if(nums[i] & rightmost) b1=b1^nums[i];    // If set, put in Bucket 1
            else b2=b2^nums[i];                        // Otherwise, put in Bucket 2
        }
        return {b1,b2};                   // Equal numbers cancel; singles remain
    }
};