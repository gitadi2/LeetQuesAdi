/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let n=nums.length;
    let low=0;
    let high=n-1;
    let res=n;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        if(nums[guess]>=target){
            res=guess;
            high=guess-1;
        }
        else{
            low=guess+1;
        }
    }
    return res;
};