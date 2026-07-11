/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let n=nums1.length;
    let m=nums2.length;

    if(n>m){
        return findMedianSortedArrays(nums2,nums1);
    }

    let low=0;
    let high=n;

    while(low<=high){
        let cut1=Math.floor((low+high)/2);
        let cut2=Math.floor((n+m+1)/2)-cut1;

        let left1;
        let left2;
        let right1;
        let right2;

        if(cut1==0){
            left1=-Infinity;
        }
        else{
            left1=nums1[cut1-1];
        }

        if(cut2==0){
            left2=-Infinity;
        }
        else{
            left2=nums2[cut2-1];
        }

        if(cut1==n){
            right1=Infinity;
        }
        else{
            right1=nums1[cut1];
        }

        if(cut2==m){
            right2=Infinity;
        }
        else{
            right2=nums2[cut2];
        }

        if(left1<=right2 && left2<=right1){
            if((n+m)%2==0){
                return (Math.max(left1,left2)+Math.min(right1,right2))/2.0;
            }
            else{
                return Math.max(left1,left2);
            }
        }

        if(left1>right2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
    }

    return 0.0;
};