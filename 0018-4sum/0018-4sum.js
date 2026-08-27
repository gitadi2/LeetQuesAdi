/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums,target) {
    let n=nums.length;
    // Array ko sort kardo
    nums.sort((a,b)=>a-b);
    let res=[];                         // Resultant 2D array

    // First element fix karo
    for(let i=0;i<n-3;i++){
        // Duplicate first element skip karo
        if(i>0 && nums[i]===nums[i-1]){
            continue;
        }

        // Second element fix karo
        for(let j=i+1;j<n-2;j++){
            // Duplicate second element skip karo
            if(j>i+1 && nums[j]===nums[j-1]){
                continue;
            }

            let left=j+1;              // Third element
            let right=n-1;             // Fourth element

            while(left<right){
                let sum=nums[i]+nums[j]+nums[left]+nums[right];

                if(sum===target){
                    // Quadruplet mil gaya
                    res.push([
                        nums[i],
                        nums[j],
                        nums[left],
                        nums[right]
                    ]);

                    // Duplicate third element skip karo
                    while(left<right && nums[left]===nums[left+1]){
                        left++;
                    }
                    // Duplicate fourth element skip karo
                    while(left<right && nums[right]===nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(sum<target){
                    // Sum chota hai
                    left++;
                }
                else{
                    // Sum bada hai
                    right--;
                }
            }
        }
    }
    return res;
};