// Sorting + Binary Search Approach

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();

        // arr2 ko sort karo
        sort(arr2.begin(),arr2.end());

        int res=0;

        // arr1 ko traverse karo
        for(int i=0;i<n;i++){
            // First element find karo jo arr1[i]-d se bada ya equal ho
            int idx=lower_bound(arr2.begin(),arr2.end(),arr1[i]-d)-arr2.begin();
            // Agar koi element range [arr1[i]-d, arr1[i]+d] mein nahi mila
            if(idx==m || arr2[idx]>arr1[i]+d){
                res++;
            }
        }
        return res;
    }
};