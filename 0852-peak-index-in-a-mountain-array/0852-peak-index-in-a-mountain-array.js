/**
 * @param {number[]} arr
 * @return {number}
 */
var peakIndexInMountainArray = function(arr) {
    let n=arr.length;
    let low=0;
    let high=n-1;
    let res=-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        if(arr[guess]<arr[guess+1]){
            low=guess+1;
        }
        else{
            res=guess;
            high=guess-1;
        }
    }
    return res;
};