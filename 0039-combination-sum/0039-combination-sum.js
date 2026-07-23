/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum=function(candidates,target){

    function fun(candidates,n,target,idx,diary,sum,res){

        // Last Stage wla Condition
        if(idx===n){
            if(sum===target){
                res.push([...diary]);
            }
            return;
        }

        // Agar nhi hi lena hai
        fun(candidates,n,target,idx+1,diary,sum,res);

        // Agar Condition wla lena hai par unlimited times le sktey hai
        if(candidates[idx]+sum<=target){

            // Le sktey hai
            diary.push(candidates[idx]);
            sum+=candidates[idx];

            // Explore karlo
            fun(candidates,n,target,idx,diary,sum,res);

            // Hta do; reverse karlo
            diary.pop();
            sum-=candidates[idx];
        }
    }

    let n=candidates.length;
    let sum=0;

    let diary=[];
    let res=[];

    // Recursive Function Call karlo
    fun(candidates,n,target,0,diary,sum,res);

    return res;
};