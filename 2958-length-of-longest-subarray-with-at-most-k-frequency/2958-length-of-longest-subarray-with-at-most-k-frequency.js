/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

var maxSubarrayLength = function(nums,k) {
    let n=nums.length;
    let freq=new Map();

    let i=0;
    let j=0;
    let res=0;

    while(j<n){
        freq.set(nums[j],(freq.get(nums[j])||0)+1);

        while(freq.get(nums[j])>k){

            freq.set(nums[i],freq.get(nums[i])-1);
            i++;
        }
        res=Math.max(res,j-i+1);
        j++;
    }
    return res;
};