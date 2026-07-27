public class Solution {
    public int MaxProduct(int[] nums) {

        int a=0;
        int b=0;

        for(int i=0;i<nums.Length;i++){
            if(nums[i]>a){
                b=a;
                a=nums[i];
            }
            else if(nums[i]>b){
                b=nums[i];
            }
        }
        return (a-1)*(b-1);
    }
}