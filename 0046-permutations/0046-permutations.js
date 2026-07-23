/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute=function(nums){

    function fun(nums,n,idx,diary,res,vis){

        // Last wla stage ka case lelo
        if(idx===n){
            res.push([...diary]);
            return;
        }

        for(let i=0;i<n;i++){

            if(!vis.get(nums[i])){

                // Agar visited hogya hai
                vis.set(nums[i],true);
                diary.push(nums[i]);

                // Explore karlo
                fun(nums,n,idx+1,diary,res,vis);

                // Reverse karlo
                diary.pop();
                vis.set(nums[i],false);
            }
        }
    }

    let n=nums.length;
    let diary=[];
    let res=[];
    let vis=new Map();

    // Recursive Function call karlo
    fun(nums,n,0,diary,res,vis);

    return res;
};