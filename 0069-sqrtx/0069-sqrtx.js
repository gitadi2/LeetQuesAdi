/**
 * @param {number} x
 * @return {number}
 */
var mySqrt=function(x){

    // agar x 0 ya 1 hai
    if(x<=1){
        return x;
    }

    let l=1,h=x;
    let ans=0;

    // binary search chalao
    while(l<=h){

        let m=Math.floor(l+(h-l)/2);

        // agar square root mil gaya
        if(m===Math.floor(x/m)){
            return m;
        }

        // agar square chota hai
        if(m<Math.floor(x/m)){

            ans=m;
            l=m+1;
        }

        // warna left mei jao
        else{
            h=m-1;
        }
    }

    // answer return kardo
    return ans;
};