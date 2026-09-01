// By DP Approach  (Time Complexity O[n^2])

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        // Ek Resultant ans arry bna lo of size n
        vector<int>res(n);   
        int i,j;

        for(i=0;i<n;i++){
            // Sarey elements ko lo uskey liye loop
            res[i]=1;                              // Har kisika LIS 1 toh hoga hi  
            for(j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    // agr previous element chota hai than current element tabhi lena hai 
                    res[i]=max(res[i],res[j]+1);            // max lelo par previous LIS mein 1 add karke
                } 
            }
        }
        int ans=1;                  // By Default 1 toh rahega hi 

        for(i=0;i<n;i++){
            ans=max(ans,res[i]);        // purey ans se jo max nikla whi final 
        }
        return ans;
    }
};