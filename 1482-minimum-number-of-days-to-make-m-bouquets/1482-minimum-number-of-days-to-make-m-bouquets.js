/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minDays = function(bloomDay, m, k) {
    function fun(bloomDay,n,m,k,guess){
        let flower=0;
        let bouquet=0;

        for(let i=0;i<n;i++){
            if(bloomDay[i]<=guess){
                flower++;
            }
            else{
                bouquet=bouquet+Math.floor(flower/k);
                flower=0;
            }
        }

        bouquet=bouquet+Math.floor(flower/k);

        if(bouquet>=m){
            return true;
        }
        else{
            return false;
        }
    }

    let n=bloomDay.length;

    if(m*k>n){
        return -1;
    }

    let low=Infinity;
    let high=-Infinity;

    for(let i=0;i<n;i++){
        low=Math.min(low,bloomDay[i]);
        high=Math.max(high,bloomDay[i]);
    }

    let res=-1;

    while(low<=high){
        let guess=Math.floor((low+high)/2);

        if(fun(bloomDay,n,m,k,guess)){
            res=guess;
            high=guess-1;
        }
        else{
            low=guess+1;
        }
    }

    return res;
};