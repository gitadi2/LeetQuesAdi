/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let n=matrix.length;
    let m=matrix[0].length;

    let low=0;
    let high=n*m-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        let row=Math.floor(guess/m);
        let col=guess%m;

        if(matrix[row][col]==target){
            return true;
        }
        if(matrix[row][col]<target){
            low=guess+1;
        }
        else{
            high=guess-1;
        }
    }
    return false;
};