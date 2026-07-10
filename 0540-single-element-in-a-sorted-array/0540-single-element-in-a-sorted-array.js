/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    let n=nums.length;
    let low=0;
    let high=n-1;

    while(low<high){
        let guess=Math.floor((low+high)/2);

        if(guess%2==1){
            guess--;
        }

        if(nums[guess]==nums[guess+1]){
            low=guess+2;
        }
        else{
            high=guess;
        }
    }
    return nums[low];
};