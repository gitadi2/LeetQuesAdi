/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    function fun(piles,n,k){
        let hours=0;
        for(let i=0;i<n;i++){
            hours=hours+Math.floor(piles[i]/k);
            if(piles[i]%k!=0){
                hours++;
            }
        }
        return hours;
    }

    let n=piles.length;
    let low=1;
    let high=0;
    for(let i=0;i<n;i++){
        high=Math.max(high,piles[i]);
    }

    let res=-1;

    while(low<=high){
        let k=Math.floor((low+high)/2);

        let hour=fun(piles,n,k);

        if(hour>h){
            low=k+1;
        }
        else{
            res=k;
            high=k-1;
        }
    }
    return res;
};