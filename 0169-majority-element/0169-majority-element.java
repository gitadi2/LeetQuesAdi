class Solution {
    public int majorityElement(int[] nums) {

        int n=nums.length;
        int candidate=0;      // candidate ka track rakhney k liye
        int count=0;          // count rakhney k liye

        for(int i=0;i<n;i++){

            // if count 0 hogya
            if(count==0){
                candidate=nums[i];      // nya candidate bnaa doo
            }

            // agar same no. of candidate hotey hai as the array size
            if(nums[i]==candidate){
                // toh count ko badha do
                count++;
            }
            else{
                // count ko ghata do
                count--;
            }
        }
        return candidate;
    }
}