/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    let n=nums.length;
    let low=0;
    let high=n-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        if(nums[guess]==target){
            return true;
        }

        if(nums[low]==nums[guess] && nums[high]==nums[guess]){
            low++;
            high--;
            continue;
        }

        if(nums[low]<=nums[guess]){
            if(nums[low]<=target && target<nums[guess]){
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        else{
            if(nums[guess]<target && target<=nums[high]){
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }
    }
    return false;
};