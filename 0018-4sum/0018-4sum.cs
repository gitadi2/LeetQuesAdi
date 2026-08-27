public class Solution {
    public IList<IList<int>> FourSum(int[] nums,int target) {
        int n=nums.Length;
        // Array ko sort kardo
        Array.Sort(nums);
        IList<IList<int>>res=new List<IList<int>>();

        // First element fix karo
        for(int i=0;i<n-3;i++){
            // Duplicate first element skip karo
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            // Second element fix karo
            for(int j=i+1;j<n-2;j++){
                // Duplicate second element skip karo
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }

                int left=j+1;
                int right=n-1;

                while(left<right){
                    long sum=(long)nums[i]+nums[j]+nums[left]+nums[right];

                    if(sum==target){

                        // Quadruplet mil gaya
                        res.Add(new List<int>{
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        // Duplicate third element skip karo
                        while(left<right && nums[left]==nums[left+1]){
                            left++;
                        }

                        // Duplicate fourth element skip karo
                        while(left<right && nums[right]==nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if(sum<target){
                        // Sum chota hai
                        left++;
                    }
                    else{
                        // Sum bada hai
                        right--;
                    }
                }
            }
        }
        return res;
    }
}