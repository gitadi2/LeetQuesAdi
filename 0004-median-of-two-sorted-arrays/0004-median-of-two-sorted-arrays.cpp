class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        // humesha smaalest array poar BS lagagna haiu 
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }

        int low=0;
        int high=n;

        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=(n+m+1)/2-cut1;

            // left ke Elements Ko htaa do 
            int left1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int left2=(cut2==0)?INT_MIN:nums2[cut2-1];

            // Right ke Elements Ko hta do 
            int right1=(cut1==n)?INT_MAX:nums1[cut1];
            int right2=(cut2==m)?INT_MAX:nums2[cut2];

            // agar Partition Sahi hai 
            if(left1<=right2 && left2<=right1){
                if((n+m)%2==0){
                    // Merge wla length even nikla toh beech k 2 elements ka avg
                    return(max(left1,left2)+min(right1,right2))/2.0;
                }
                else{
                    // Odd length hai ; toh left wleyt ka max hi median hoga 
                    return max(left1,left2);
                }
            }

            if(left1>right2){
                // Left mei chley jao 
                high=cut1-1;
            }
            else{
                // Right mei chley jao 
                low=cut1+1;
            }
        }
        return 0.0;
    }
};