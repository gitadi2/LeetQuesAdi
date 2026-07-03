class Solution {
    public int search(int[] nums, int target) {
        int n=nums.length;
        int low=0;
        int high=n-1;

        while(low<=high){
            int guess = (low+high)/2;

            if (nums[guess]==target){
                return guess;
            }

            if(nums[guess]>target){
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return -1;
    }
}