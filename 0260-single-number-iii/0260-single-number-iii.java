//...Brute Force Soln (Hashing).......

class Solution {
    public int[] singleNumber(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer>mpp=new HashMap<>(); 
        //.....Traverse the Array..........
        for(int i=0;i<n;i++) {
            mpp.put(nums[i],mpp.getOrDefault(nums[i],0)+1);
        }
        ArrayList<Integer>ans=new ArrayList<>();  
        //........Iterate through the HashMap.......
        for(Map.Entry<Integer,Integer>it:mpp.entrySet()) {
            if(it.getValue()==1) {
                ans.add(it.getKey());
            }
        }
        return new int[]{ans.get(0),ans.get(1)};
    }
}