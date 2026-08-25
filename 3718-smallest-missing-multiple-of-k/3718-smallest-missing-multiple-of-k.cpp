class Solution {
public:
    int missingMultiple(vector<int>&nums,int k){
        // HashMap / HashSet bna lo
        unordered_set<int>mp;

        // Saare elements ko HashSet mei dald do
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }

        // k ke multiples check kartey jao
        for(int i=1;;i++){
            int x=k*i;
            // Agar multiple HashSet mei nhi hai
            if(mp.find(x)==mp.end()){
                return x;
            }
        }
        return -1;
    }
};