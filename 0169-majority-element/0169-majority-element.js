/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {

    let n=nums.length;
    let candidate=0;      // candidate ka track rakhney k liye
    let count=0;          // count rakhney k liye

    for(let i=0;i<n;i++){

        // if count 0 hogya
        if(count===0){
            candidate=nums[i];      // nya candidate bnaa doo
        }

        // agar same no. of candidate hotey hai as the array size
        if(nums[i]===candidate){
            // toh count ko badha do
            count++;
        }
        else{
            // count ko ghata do
            count--;
        }
    }
    return candidate;
};