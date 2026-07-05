/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    let stk=[];
    let n=heights.length;
    let res=0;

    for(let i=0;i<=n;i++){
        let curr=(i==n)?0:heights[i];

        while(stk.length!=0 && heights[stk[stk.length-1]]>curr){
            let h=heights[stk[stk.length-1]];
            stk.pop();

            let left=(stk.length==0)?-1:stk[stk.length-1];
            let width=i-left-1;

            res=Math.max(res,h*width);
        }

        stk.push(i);
    }

    return res;
};