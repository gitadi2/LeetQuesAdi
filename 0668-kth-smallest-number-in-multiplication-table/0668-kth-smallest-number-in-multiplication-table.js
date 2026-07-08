/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(m, n, k) {
    function fun(m,n,guess){
        let count=0;

        for(let i=1;i<=m;i++){
            count=count+Math.min(n,Math.floor(guess/i));
        }
        return count;
    }

    let low=1;
    let high=m*n;
    let res=-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        let ans=fun(m,n,guess);

        if(ans<k){
            low=guess+1;
        }
        else{
            res=guess;
            high=guess-1;
        }
    }
    return res;
};