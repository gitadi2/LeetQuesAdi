class Solution {
public:
    bool uniformArray(vector<int>&nums1){
        int mn=INT_MAX;

        // Sabse chota odd element find kardo
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                mn=min(mn,nums1[i]);
            }
        }
        // Agar koi odd element hi nahi hai, Toh saare elements already even hain
        if(mn==INT_MAX){
            return true;
        }
        // Check karo ki koi even element smallest odd se chota toh nahi hai
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0 && nums1[i]<mn){
                return false;
            }
        }
        return true;
    }
};