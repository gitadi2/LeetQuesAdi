class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n=nums.length;
        int low=0;
        int high=n-1;

        while(low<high){
            int guess=(low+high)/2;

            if(guess%2==1){
                guess--;
            }

            if(nums[guess]==nums[guess+1]){
                low=guess+2;
            }
            else{
                high=guess;
            }
        }
        return nums[low];
    }
}