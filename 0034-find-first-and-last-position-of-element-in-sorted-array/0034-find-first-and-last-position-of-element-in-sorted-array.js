/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    function first(nums,target){
        let n=nums.length;
        let low=0;
        let high=n-1;
        let res=-1;

        while(low<=high){
            let guess=Math.floor((low+high)/2);

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

    function last(nums,target){
        let n=nums.length;
        let low=0;
        let high=n-1;
        let res=-1;

        while(low<=high){
            let guess=Math.floor((low+high)/2);

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

    let firstIdx=first(nums,target);
    let lastIdx=last(nums,target);

    return [firstIdx,lastIdx];
    
};