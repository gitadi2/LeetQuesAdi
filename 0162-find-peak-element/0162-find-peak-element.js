/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    let n=nums.length;

    if(n==1){
        return 0;
    }

    let low=0;
    let high=n-1;

    while(low<high){
        let guess=Math.floor((low+high)/2);

        if(nums[guess]>nums[guess+1]){
            high=guess;
        }
        else{
            low=guess+1;
        }
    }
    return low;
};
    