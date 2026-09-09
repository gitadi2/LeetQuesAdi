class Solution {
    public int jump(int[] nums) {
        int n=nums.length;

        int jumps=0;                  // Initially jumps ko 0 se shuru karo
        int l=0;                      // Initially left ptr 0 se start hoga
        int r=0;                      // Initially right ptr 0 se start hoga

        while(r<n-1){
            // Jab tak right ptr last index tak nahi pahucha
            int farthest=0;           // Farthest ko bhi 0 se shuru karo

            for(int i=l;i<=r;i++){
                // Current l and r ke liye pura range traverse kardo
                farthest=Math.max(farthest,i+nums[i]);
            }
            l=r+1;                    // Next mein l ptr update hogya
            r=farthest;               // Next mein r ptr farthest hi banega

            jumps++;                  // Range update karke jumps ke no. ko badha do
        }
        return jumps;
    }
}