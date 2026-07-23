public class Solution {

    public void fun(int[] candidates,int n,int target,int idx,List<int> diary,int sum,IList<IList<int>> res){

        // Last Stage wla Condition
        if(idx==n){
            if(sum==target){
                res.Add(new List<int>(diary));
            }
            return;
        }

        // Agar nhi hi lena hai
        fun(candidates,n,target,idx+1,diary,sum,res);

        // Agar Condition wla lena hai par unlimited times le sktey hai
        if(candidates[idx]+sum<=target){

            // Le sktey hai
            diary.Add(candidates[idx]);
            sum+=candidates[idx];

            // Explore karlo
            fun(candidates,n,target,idx,diary,sum,res);

            // Hta do; reverse karlo
            diary.RemoveAt(diary.Count-1);
            sum-=candidates[idx];
        }
    }

    public IList<IList<int>> CombinationSum(int[] candidates,int target){

        int n=candidates.Length;
        int sum=0;

        List<int> diary=new List<int>();
        IList<IList<int>> res=new List<IList<int>>();

        // Recursive Function Call karlo
        fun(candidates,n,target,0,diary,sum,res);

        return res;
    }
}