class Solution{
public:
    int minimumDeletions(vector<int>&nums){
        int n=nums.size(); // array ki length le lo

        int mn=0; // minimum element ka index
        int mx=0; // maximum element ka index

        for(int i=1;i<n;i++){
            if(nums[i]<nums[mn]){
                mn=i; // minimum ka index update kar do
            }

            if(nums[i]>nums[mx]){
                mx=i; // maximum ka index update kar do
            }
        }

        if(mn>mx){
            swap(mn,mx); // mn ko left side aur mx ko right side rakh do
        }

        int ans=mx+1; // dono ko left se remove karne ka case
        ans=min(ans,n-mn); // dono ko right se remove karne ka case
        ans=min(ans,mn+1+n-mx); // ek left aur ek right se remove karne ka case

        return ans; // minimum operations return kar do
    }
};