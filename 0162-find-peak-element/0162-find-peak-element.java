class Solution {
    public int findPeakElement(int[] nums) {
        int n=nums.length;

        if(n==1){
            return 0;
        }

        int low=0;
        int high=n-1;

        while(low<high){
            int guess=(low+high)/2;

            if(nums[guess]>nums[guess+1]){
                high=guess;
            }
            else{
                low=guess+1;
            }
        }
        return low;
    }
}