class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxInd=0;                     // Max index lelo shuru mein 0 se init kardo 

        for(int i=0;i<n;i++){
            // Purey Array ko traverse kardo 
            // agar Reachable nhi hai from current state 
            if(i>maxInd){
                return false;
            }
            maxInd=max(maxInd,i+nums[i]);           // Max Index ko update kartey raho 

            // agar Reach kargya last mein 
            if(maxInd>=n-1){
                return true;
            }
        }
        return true;                // Agar Pura hi shi chl gya toh bhi return true 
    }
};