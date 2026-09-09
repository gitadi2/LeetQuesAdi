class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        int jumps=0;                  // Initially jumpos ko 0 se shuru karo 
        int l=0;                      // Intially left ptr 0 se start hoga for Min pt of Range pref this 
        int r=0;                      // Intially rt ptr 0 se start hoga for max pt of Range pref this 

        while(r<n-1){
            // jab tak Rt ptr within the Array chal rha hai tab tak all goog
            int farthest=0;          // Farthest ko bhi 0 se shuru karo 
            for(int i=l;i<=r;i++){
                // Current l and r k liye pura arry traverse kardo 
                farthest=max(farthest,i+nums[i]);         // Range from l to r dekhlo
            }
            l=r+1;                              // Next mein l ptr update hogya 
            r=farthest;                         // Next mei r ptr farthest hi bnega 

            jumps++;                            // Range upd karkey jumps k no. ko badha do 
        }
        return jumps;
    }
};