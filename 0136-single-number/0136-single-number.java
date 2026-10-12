class Solution {
    public int singleNumber(int[] nums) {
        int n=nums.length;
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
        }
        return xr;
    }
}