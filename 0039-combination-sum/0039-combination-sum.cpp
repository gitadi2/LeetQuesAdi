class Solution {
public:
void fun(vector<int>& candidates,int n, int target, int idx, vector<int>&diary,int sum,vector<vector<int>>&res){

    // Last Stage wla Condittion 
    if(idx==n){
        if(sum==target){
            res.push_back(diary);
        }
        return;
    }

    // Agar nhi hi lena hai; toh us condn ko likh k koi matlab nhi hai ---> seedha move fwd
    fun(candidates,n,target,idx+1,diary,sum,res);

    // Agar Condition wla lena hai par unlimited times le sktey hai 
    if(candidates[idx]+sum<=target){
        // le sktey hai
        diary.push_back(candidates[idx]);
        sum+=candidates[idx];

        // explore karlo but revisit karke nxt state mei jakey nhi 
        fun(candidates,n,target,idx,diary,sum,res);

        // hta do; reverse karlo 
        diary.pop_back();
        sum-=candidates[idx];
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n=candidates.size();
        int sum=0;
        vector<int>diary;
        vector<vector<int>>res;

        // recursive Function Call karlo
        fun(candidates,n,target,0,diary,sum,res);

        return res;             // Final Resulatnt 2D array return kardo 
    }
};