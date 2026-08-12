public class Solution {
    public int MaxSubarrayLength(int[] nums,int k) {
        int n=nums.Length;
        Dictionary<int,int>freq=new Dictionary<int,int>();

        int i=0;
        int j=0;
        int res=0;

        while(j<n){
            if(freq.ContainsKey(nums[j])){
                freq[nums[j]]++;
            }
            else{
                freq[nums[j]]=1;
            }

            while(freq[nums[j]]>k){
                freq[nums[i]]--;
                i++;
            }
            res=Math.Max(res,j-i+1);
            j++;
        }
        return res;
    }
}