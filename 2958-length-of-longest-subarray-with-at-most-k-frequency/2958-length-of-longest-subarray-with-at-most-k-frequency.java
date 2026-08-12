class Solution {
    public int maxSubarrayLength(int[] nums,int k) {
        int n=nums.length;

        HashMap<Integer,Integer>freq=new HashMap<>();   // Har element ki frequency rakhne k liye HashMap

        int i=0;                           // Window ka starting point
        int j=0;                           // Window ka ending point
        int res=0;                         // Maximum length shuru mei 0

        while(j<n){
            freq.put(nums[j],freq.getOrDefault(nums[j],0)+1);  // Current element ki frequency badha do

            // Agar kisi element ki frequency k se jyada hogyi
            while(freq.get(nums[j])>k){
                freq.put(nums[i],freq.get(nums[i])-1);         // Left wley element ki frequency ghata do
                i++;                                           // Window ko left se shrink karo
            }

            // Ab current window valid hai
            res=Math.max(res,j-i+1);             // Maximum length update kardo

            j++;                                // Right side se window extend karo
        }
        return res;
    }
}