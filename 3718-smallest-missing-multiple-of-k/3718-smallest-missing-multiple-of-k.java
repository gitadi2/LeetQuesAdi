class Solution {
    public int missingMultiple(int[] nums,int k) {
        // HashSet bna lo
        HashSet<Integer>mp=new HashSet<>();

        // Saare elements ko HashSet mei dald do
        for(int i=0;i<nums.length;i++){
            mp.add(nums[i]);
        }

        // k ke multiples check kartey jao
        for(int i=1;;i++){
            int x=k*i;
            // Agar multiple HashSet mei nhi hai
            if(!mp.contains(x)){
                return x;
            }
        }
    }
}