class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();   
        int low=0; 
        int high=n-1;

        while(low<=high){
            // Till the Time low is less than or equal to high this will be true 
            int guess=(low+high)/2;           // Random Element is taken as the Mid one 
           
            if(nums[guess]==target){
                // If the Element guessed is found 
                return guess;
            }

            if(nums[guess]>target){
                // the greater one 
                high=guess-1;
            }
            else{
                // the smaller or lesser one 
                low=guess+1;
            }
        }
        return -1;                     // If the element is not present at all 
    }
};