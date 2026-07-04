class Solution {
public int first(int[]nums,int target){
    int n=nums.length;
    int low=0;
    int high=n-1;
    int res=-1;

    while(low<=high){
        int guess=(high+low)/2;

        if(nums[guess]<target){
            low=guess+1;
        }
        else if(nums[guess]>target){
            high=guess-1;
        }
        else{
            res=guess;
            high=guess-1;
        }
    }
    return res;
}

public int last(int[]nums,int target){
    int n=nums.length;
    int low=0;
    int high=n-1;
    int res=-1;

    while(low<=high){
        int guess=(high+low)/2;

        if(nums[guess]<target){
            low=guess+1;
        }
        else if(nums[guess]>target){
            high=guess-1;
        }
        else{
            res=guess;
            low=guess+1;
        }
    }
    return res;
}
    public int[] searchRange(int[] nums, int target) {
        int firstIdx=first(nums,target);
        int lastIdx=last(nums,target);

        return new int[]{firstIdx,lastIdx};
    }
}