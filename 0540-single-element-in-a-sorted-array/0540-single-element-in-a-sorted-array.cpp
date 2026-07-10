class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res=-1; 

        while(low<high){
            int guess=(low+high)/2;

            if(guess%2==1){
                guess--;             // Guess ko humesha even Index par hi rakho; cuz even idx s start
            }

            if(nums[guess]==nums[guess+1]){
                // Toh right mein chley jao 
                low=guess+2;
            }
            else{
                // Toh left mei jao wha Single wla milega
                high=guess-1;
            }
        }
        return nums[low];          // Final ans low wla hoga 
    }
};