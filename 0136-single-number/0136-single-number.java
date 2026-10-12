// Brute Force Approach 

class Solution {
    public int singleNumber(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer>mpp=new HashMap<>();  // Unordered HashMap bna lo

        // Traverse Through the Elements of the Array
        for(int i=0;i<n;i++) {
            mpp.put(nums[i],mpp.getOrDefault(nums[i],0)+1); // Jo jo element mila uski freq inc. mardo 
        }
        // Ab HashMap mei loop kro
        for(Map.Entry<Integer,Integer>it:mpp.entrySet()) {
            if(it.getValue()==1) {
                return it.getKey();   // Agar frequency 1 hai toh return kardo
            }
        }
        return 0;
    }
}