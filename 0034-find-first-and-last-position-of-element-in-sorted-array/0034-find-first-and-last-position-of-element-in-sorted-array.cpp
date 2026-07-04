class Solution {
public:
// For the Starting Postion
int first(vector<int>&nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int res=-1;                     // If the Start pos as the target not there return -1

    while(low<=high){
        int guess=(low+high)/2;

        if(nums[guess]<target){
            low=guess+1;
        }
        else if(nums[guess]>target){
            high=guess-1;
        }
        else{
            // nums[guess]==target
            res=guess;             // Res mein store karlunga guess value ko 
            high=guess-1;          // First wala chahiye to peechey jana hoga
        }
    }
    return res;
}

// For the Last position
int last(vector<int>&nums,int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int res=-1;                          // If the start pos as the target will not be there then -1

    while(low<=high){
        int guess=(low+high)/2;
        if(nums[guess]<target){
            low=guess+1;
        }
        else if(nums[guess]>target){
            high=guess-1;
        }
        else{
            // nums[guess]==target
            res=guess;              //Res mein store karlunga guess ki value kpo
            low=guess+1;            // Last wla chahiye to agey jana hoga 
        }
    }
    return res;              
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIdx=first(nums,target);           // Ye first index ko fetch karega fun call se
        int lastIdx=last(nums,target);             //Ye last index ko fetch karega from fun call

        return {firstIdx,lastIdx};                 //Final indices dega as required
        
    }
};