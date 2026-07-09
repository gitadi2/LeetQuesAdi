class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res=n;             // n isliye lerhe hain cuz agar nhi aya kuch to whi ans aajaega 

        while(low<=high){
            int guess=(low+high)/2;

            if(nums[guess]>=target){
                res=guess;    // ye wala ho skta hai target ka index
                high=guess-1;      // Left mein jao
            }
            else{
                low=guess+1;       // Right mei jao 
            }
        }
        return res;            // Index final wla return kardo 
    }
};