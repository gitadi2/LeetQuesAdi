class Solution {
public:
    int maxSubarrayLength(vector<int>& nums,int k) {
        int n=nums.size();

        unordered_map<int,int>freq;       // Har element ki frequency rakhne k liye HashMap

        int i=0;                           // Window ka starting point
        int j=0;                           // Window ka ending point
        int res=0;                         // Maximum length shuru mei 0

        while(j<n){
            freq[nums[j]]++;               // Current element ki frequency badha do

            // Agar kisi element ki frequency k se jyada hogyi
            while(freq[nums[j]]>k){
                freq[nums[i]]--;           // Left wley element ki frequency ghata do
                i++;                       // Window ko left se shrink karo
            }

            // Ab current window valid hai
            res=max(res,j-i+1);             // Maximum length update kardo

            j++;                           // Right side se window extend karo
        }
        return res;
    }
};