/**
 * @param {number} n
 * @return {boolean}
 */
var checkDivisibility = function(n) {
    let sum=0;
    let product=1;
    let x=n;

    // Har digit ko nikalenge
    while(x!=0){
        let digit=x%10;
        x=Math.floor(x/10);

        sum+=digit;
        product*=digit;
    }
    // Divisibility check
    return n%(sum+product)===0;
};