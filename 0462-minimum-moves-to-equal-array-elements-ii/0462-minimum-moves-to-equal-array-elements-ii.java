class Solution {
    public int minMoves2(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);          // Array ko sort karo
        int mid=nums[n/2];          // Median find karo

        int res=0;

        // Median ke saath difference calculate karo
        for(int i=0;i<n;i++){
            res+=Math.abs(nums[i]-mid);
        }
        return res;
    }
}