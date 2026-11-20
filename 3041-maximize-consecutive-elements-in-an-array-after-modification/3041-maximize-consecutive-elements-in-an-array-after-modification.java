// Sorting + Greedy DP (Space Optimized)

class Solution {
    public int maxSelectedElements(int[] nums) {
        int n=nums.length;

        Arrays.sort(nums);

        int res=1;
        int prev=nums[0];

        int dp0=1;
        int dp1=1;

        for(int i=1;i<n;i++){
            if(nums[i]==prev){
                dp1=dp0+1;
            }
            else if(nums[i]==prev+1){
                dp0++;
                dp1++;
            }
            else if(nums[i]==prev+2){
                dp0=dp1+1;
                dp1=1;
            }
            else{
                dp0=1;
                dp1=1;
            }
            res=Math.max(res,Math.max(dp0,dp1));
            prev=nums[i];
        }
        return res;
    }
}