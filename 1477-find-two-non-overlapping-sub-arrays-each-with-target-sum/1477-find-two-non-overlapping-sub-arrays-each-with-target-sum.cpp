// By Prefix Sum + Hash Table Method

class Solution {
public:
    int minSumOfLengths(vector<int>&arr,int target) {
        int n=arr.size();

        unordered_map<int,int>mp;       // Prefix sum ka last index store karo
        mp[0]=-1;

        vector<int>best(n,INT_MAX);     // i tak ka minimum subarray length
        int sum=0;
        int res=INT_MAX;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            // Agar required prefix sum mil gaya
            if(mp.find(sum-target)!=mp.end()){
                int j=mp[sum-target];
                int len=i-j;

                // Current subarray se pehle koi valid subarray hai
                if(j>=0 && best[j]!=INT_MAX){
                    res=min(res,len+best[j]);
                }
                // i tak ka minimum length update karo
                if(i==0){
                    best[i]=len;
                }
                else{
                    best[i]=min(best[i-1],len);
                }
            }
            else{
                // Pehle ka best answer carry forward karo
                if(i>0){
                    best[i]=best[i-1];
                }
            }
            // Prefix sum ka latest index store karo
            mp[sum]=i;
        }
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};