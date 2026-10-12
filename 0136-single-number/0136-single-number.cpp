class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;                 // Unordered hashMap bna lo 
        // Traverse Through the Elemnts of the Array 
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;           // Jo jo elemnt mila jata hai uski freq in the map inc krtey raho 
        }
        // Ab HashMap mei loop kro 
        for(auto it:mpp){
            if(it.second==1) return it.first;       // Agr freq 1 hai toh return kardo 
        }
    return 0;
    }
};