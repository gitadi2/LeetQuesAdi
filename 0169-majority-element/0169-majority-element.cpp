class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();    
        int candidate=0;         // candidate ka track rakhney k liye 
        int count=0;             //count rakhney k liye 

        for(int i=0;i<n;i++){
            
            // if count 0 hogya 
            if(count==0){
                candidate=nums[i];          // Nya Candiadate bnaa doo 
            }

            // agar se no. of candidate hotey hai as the array size 
            if(nums[i]==candidate){
                // Toh count ko badha do 
                count++;
            }
            else{
                //Count ko ghata do 
                count--;
            }
        }   
        return candidate;
    }
};