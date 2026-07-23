class Solution {

    public void fun(int[] nums,int n,int idx,List<Integer> diary,List<List<Integer>> res,HashMap<Integer,Boolean> vis){

        // Last wla stage ka case lelo
        if(idx==n){
            res.add(new ArrayList<>(diary));
            return;
        }

        for(int i=0;i<n;i++){

            if(!vis.getOrDefault(nums[i],false)){

                // Agar visited hogya hai
                vis.put(nums[i],true);
                diary.add(nums[i]);

                // Explore karlo
                fun(nums,n,idx+1,diary,res,vis);

                // Reverse karlo
                diary.remove(diary.size()-1);
                vis.put(nums[i],false);
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {

        int n=nums.length;

        List<Integer> diary=new ArrayList<>();
        List<List<Integer>> res=new ArrayList<>();
        HashMap<Integer,Boolean> vis=new HashMap<>();

        // Recursive Function call karlo
        fun(nums,n,0,diary,res,vis);

        return res;
    }
}