class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high){
            int guess=(low+high)/2;

            // Common case ko lelo
            if(nums[guess]==target){
                return guess;
            }

            // Guess wala Part 1 mein agya toh 
            if(nums[guess]>nums[n-1]){
                // if wala condn satisfy hua toh part 1 mei hai
                if(nums[guess]<target){
                    low=guess+1;             // Right mein chley jao
                }
                else{
                    // nums[guess]>target
                    if(nums[0]>target){
                        low=guess+1;            //Right mein hi dekho
                    }
                    else{
                        high=guess-1;            //Left mein dekho
                    }
                }
                continue;
            }

            // Guess wala Part 2 mein agya toh
            if(nums[guess]>target){
                high=guess-1;                  // Left mein dekho
            }
            else{
                if(nums[n-1]<target){
                    high=guess-1;             //Left mein hi dekho
                }
                else{
                    low=guess+1;              // Right mein dekho
                }
            }
        }
        return -1;                           // agat kuch nhi hi mila tab -1 return kardo   
    }
};