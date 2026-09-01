// By Binary Search Approach {THE MOST OPTIMAL APPROACH}

class Solution {
public:
    int lengthOfLIS(vector<int>&nums) {
        int n=nums.size();
        // Ek Resultant ans array bna lo
        vector<int>res;

        for(int i=0;i<n;i++){
            // Current element ko lo
            int x=nums[i];

            // Binary Search se first element >= x dhundho
            int left=0;
            int right=res.size();

            while(left<right){
                int mid=left+(right-left)/2;
                if(res[mid]<x){
                    // Agar mid wala element chota hai
                    // Toh right side mein jao
                    left=mid+1;
                }
                else{
                    // Agar mid wala element bada ya equal hai
                    // Toh left side mein jao
                    right=mid;
                }
            }
            // Agar koi element >= x nhi mila
            if(left==res.size()){
                // Current element ko end mein daal do
                res.push_back(x);
            }
            else{
                // Smallest possible ending value update karo
                res[left]=x;
            }
        }
        // res ka size hi LIS ki length hai
        return res.size();
    }
};