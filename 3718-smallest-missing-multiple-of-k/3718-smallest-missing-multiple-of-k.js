/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var missingMultiple = function(nums, k) {
    // HashSet bna lo
    let mp=new Set();

    // Saare elements ko HashSet mei dald do
    for(let i=0;i<nums.length;i++){
        mp.add(nums[i]);
    }

    // k ke multiples check kartey jao
    for(let i=1;;i++){
        let x=k*i;

        // Agar multiple HashSet mei nhi hai
        if(!mp.has(x)){
            return x;
        }
    }
};