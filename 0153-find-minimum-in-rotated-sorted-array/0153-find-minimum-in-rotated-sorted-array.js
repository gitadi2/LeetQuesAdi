/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let n=nums.length;
    let low=0;
    let high=n-1;
    let res=-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        if(nums[guess]>nums[n-1]){
            low=guess+1;
        }
        else{
            res=guess;
            high=guess-1;
        }
    }
    return nums[res];
};