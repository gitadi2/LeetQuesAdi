class Solution {
public:
    vector<vector<int>> fourSum(vector<int>&nums,int target) {
        int n=nums.size();

        // Array ko sort kardo
        sort(nums.begin(),nums.end());

        vector<vector<int>>res;                  // Resultant 2D array

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
                int left=j+1;                   // Third element
                int right=n-1;                  // Fourth element

                while(left<right){
                    long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        // Quadruplet mil gaya
                        res.push_back({
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
};