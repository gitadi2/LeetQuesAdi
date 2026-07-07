/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    let n=citations.length;
    let low=0;
    let high=n-1;
    let res=0;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        if(citations[guess]>=n-guess){
            res=n-guess;
            high=guess-1;
        }
        else{
            low=guess+1;
        }
    }
    return res;
};