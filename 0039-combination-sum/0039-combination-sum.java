class Solution {

    public void fun(int[] candidates,int n,int target,int idx,List<Integer> diary,int sum,List<List<Integer>> res){

        // Last Stage wla Condition
        if(idx==n){
            if(sum==target){
                res.add(new ArrayList<>(diary));
            }
            return;
        }

        // Agar nhi hi lena hai; toh us condn ko likh k koi matlab nhi hai ---> seedha move fwd
        fun(candidates,n,target,idx+1,diary,sum,res);

        // Agar Condition wla lena hai par unlimited times le sktey hai
        if(candidates[idx]+sum<=target){

            // Le sktey hai
            diary.add(candidates[idx]);
            sum+=candidates[idx];

            // Explore karlo but revisit karke nxt state mei jakey nhi
            fun(candidates,n,target,idx,diary,sum,res);

            // Hta do; reverse karlo
            diary.remove(diary.size()-1);
            sum-=candidates[idx];
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates,int target){

        int n=candidates.length;
        int sum=0;

        List<Integer> diary=new ArrayList<>();
        List<List<Integer>> res=new ArrayList<>();

        // Recursive Function Call karlo
        fun(candidates,n,target,0,diary,sum,res);

        return res;
    }
}