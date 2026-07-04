class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res=-1;            // agar ans nhi mila min toh auto ans -1 hoga 

        while(low<=high){
            int guess=(low+high)/2;      // Random element extract k liye hai

            if(nums[guess]>nums[n-1]){
                // Part 2 mai hai 
                low=guess+1;
            }
            else{
                // nums[guess]<nums[guess+1]
                res=guess;
                high=guess-1;
            }
        }
        return nums[res];
    }
};