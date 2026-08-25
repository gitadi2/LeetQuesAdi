public class Solution {
    public int MissingMultiple(int[] nums,int k) {
        // HashSet bna lo
        HashSet<int> mp=new HashSet<int>();

        // Saare elements ko HashSet mei dald do
        for(int i=0;i<nums.Length;i++){
            mp.Add(nums[i]);
        }

        // k ke multiples check kartey jao
        for(int i=1;;i++){
            int x=k*i;
            // Agar multiple HashSet mei nhi hai
            if(!mp.Contains(x)){
                return x;
            }
        }
    }
}