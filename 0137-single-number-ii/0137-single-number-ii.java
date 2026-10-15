// BruteForce Soln

class Solution {
    public int singleNumber(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer>mpp=new HashMap<>();      //HasHmap bna lo 
        //Ab Traverse Through the Array 
        for(int i=0;i<n;i++){
            mpp.put(nums[i],mpp.getOrDefault(nums[i],0)+1);       // HashMap mein freq k sath daltey chl
        }
        // Ab Traverse in the HashMap 
        for(Map.Entry<Integer,Integer> it:mpp.entrySet()){
            if(it.getValue()==1) return it.getKey();
        }
        return 0;
    }
}