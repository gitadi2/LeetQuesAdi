class Solution {
    public int searchInsert(int[] nums, int target) {
        int n=nums.length;
        int low=0;
        int high=n-1;
        int res=n;

        while(low<=high){
            int guess=(low+high)/2;

            if(nums[guess]>=target){
                res=guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return res;
    }
}