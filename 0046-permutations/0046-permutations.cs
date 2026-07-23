public class Solution {

    public void fun(int[] nums,int n,int idx,List<int> diary,IList<IList<int>> res,Dictionary<int,bool> vis){

        // Last wla stage ka case lelo
        if(idx==n){
            res.Add(new List<int>(diary));
            return;
        }

        for(int i=0;i<n;i++){

            if(!vis.ContainsKey(nums[i]) || vis[nums[i]]==false){

                // Agar visited hogya hai
                vis[nums[i]]=true;
                diary.Add(nums[i]);

                // Explore karlo
                fun(nums,n,idx+1,diary,res,vis);

                // Reverse karlo
                diary.RemoveAt(diary.Count-1);
                vis[nums[i]]=false;
            }
        }
    }

    public IList<IList<int>> Permute(int[] nums) {

        int n=nums.Length;

        List<int> diary=new List<int>();
        IList<IList<int>> res=new List<IList<int>>();
        Dictionary<int,bool> vis=new Dictionary<int,bool>();

        // Recursive Function call karlo
        fun(nums,n,0,diary,res,vis);

        return res;
    }
}