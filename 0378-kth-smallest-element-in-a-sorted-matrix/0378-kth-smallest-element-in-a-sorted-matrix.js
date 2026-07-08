/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(matrix, k) {
    function fun(matrix,n,guess){
        let row=n-1;
        let col=0;
        let count=0;

        while(row>=0 && col<n){
            if(matrix[row][col]<=guess){
                count=count+row+1;
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }

    let n=matrix.length;

    let low=matrix[0][0];
    let high=matrix[n-1][n-1];

    let res=-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        let ans=fun(matrix,n,guess);

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