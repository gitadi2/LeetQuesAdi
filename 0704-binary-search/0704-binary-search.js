/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let n=nums.length;
    let low=0;
    let high=n-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        if(nums[guess]==target){
            return guess;
        }

        if(nums[guess]>target){
            high=guess-1;
        }
        else{
            low=guess+1;
        }
    }
    return -1;
};