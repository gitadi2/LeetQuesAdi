/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations=function(digits){
    let f=new Map();

    // HashMap dec kardo taki sab ek sath ajae(1-9 tak)
    f.set('2',"abc");
    f.set('3',"def");
    f.set('4',"ghi");
    f.set('5',"jkl");
    f.set('6',"mno");
    f.set('7',"pqrs");
    f.set('8',"tuv");
    f.set('9',"wxyz");

    let n=digits.length;
    let diary=[];
    let res=[];

    if(n===0){
        return res;
    }

    function fun(digits,n,idx,diary,res,f){

        // Last wla stage lelo
        if(idx===n){
            res.push(diary.join(""));
            return;
        }

        // Strings ko button ke nichey hai sab ek sath nilega
        let choice=f.get(digits[idx]);

        for(let j=0;j<choice.length;j++){

            // Push kardo har j k index ko
            diary.push(choice[j]);

            // Explore karlo next wley mei jakey
            fun(digits,n,idx+1,diary,res,f);

            // Reverse kardo
            diary.pop();
        }
        return;
    }

    // Recursive Call kardo intio main
    fun(digits,n,0,diary,res,f);

    return res;
};