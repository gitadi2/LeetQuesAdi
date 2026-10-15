// Brute Force Approach 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;        // Unordered HashMap bna lo 
        // Traverse through the Array 
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;                 // Hashmap mein fre daldo 
        }
        // Ab HashMap mein Traverse krna hai 
        for(auto it:mpp){
            if(it.second==1) return it.first;
        }
        return 0; 
    }
};