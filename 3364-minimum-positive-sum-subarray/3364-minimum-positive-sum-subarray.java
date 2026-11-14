// Sliding Window (Fixed Sliding Window)

class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n=nums.size();
        int res=Integer.MAX_VALUE;

        for(int len=l;len<=r;len++){
            int sum=0;
            // Calculate initial window sum
            for(int i=0;i<len;i++){
                sum+=nums.get(i);
            }
            if(sum>0){
                res=Math.min(res,sum);
            }

            // Slide the window
            for(int i=len;i<n;i++){
                sum+=nums.get(i);
                sum-=nums.get(i-len);
                if(sum>0){
                    res=Math.min(res,sum);
                }
            }
            if(res==1){
                return 1;
            }
        }
        if(res==Integer.MAX_VALUE){
            return -1;
        }
        return res;
    }
}