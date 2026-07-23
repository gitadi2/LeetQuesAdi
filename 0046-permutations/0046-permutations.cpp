class Solution {
public:
void fun(vector<int>&nums,int n,int idx, vector<int>&diary,vector<vector<int>>&res,unordered_map<int,bool>&vis){

    // Last wla stage ka case lelo 
    if(idx==n){
        res.push_back(diary);
        return;
    }

    for(int i=0;i<n;i++){
        if(!vis[nums[i]]){

            vis[nums[i]]=true;              // Agar visited hogya hai 
            diary.push_back(nums[i]);

            // Explore karlo 
            fun(nums,n,idx+1,diary,res,vis);

            // Reverse karlo 
            diary.pop_back();
            vis[nums[i]]=false;
        }
    }
}

    vector<vector<int>> permute(vector<int>& nums) {

        int n=nums.size();
        vector<int>diary;            // Shuru mei to empty hi hona hai
        vector<vector<int>>res;      //Resultant 2D array bna lo 
        unordered_map<int,bool>vis; 

        // recursive Fuction call karlo 
        fun(nums,n,0,diary,res,vis);

        return res;                 // Final resultant wla array return karlo 
    }
};