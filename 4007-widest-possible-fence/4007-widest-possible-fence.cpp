class Solution {
public:
    int maximumWidth(vector<int>&planks) {
        int n=planks.size();                       // No. of planks
        // Frequency Map bana lo
        unordered_map<int,int>freq;

        for(int i=0;i<n;i++){
            freq[planks[i]]++;                    // Har height ki frequency badha do
        }

        // Input ko midway store karna hai
        vector<int>velmoritha=planks;

        // Resultant Map
        unordered_map<int,int>res;

        int ans=0;                                 // Maximum width

        // Har unique height ko dekho
        for(auto it1:freq){
            int x=it1.first;                       // First height
            int cnt1=it1.second;                   // Frequency of first height

            // Directly x height ka plank use kar sakte hain
            res[x]+=cnt1;
            ans=max(ans,res[x]);
            // Do x wale planks ko mila kar 2*x bana sakte hain
            res[2*x]+=cnt1/2;
            ans=max(ans,res[2*x]);

            // x ke saath doosri height y ko pair karo
            for(auto it2:freq){
                int y=it2.first;                   // Second height
                int cnt2=it2.second;               // Frequency of second height

                if(y>x){
                    // x + y se new plank banega
                    res[x+y]+=min(cnt1,cnt2);
                    ans=max(ans,res[x+y]);
                }
            }
        }
        return ans;
    }
};