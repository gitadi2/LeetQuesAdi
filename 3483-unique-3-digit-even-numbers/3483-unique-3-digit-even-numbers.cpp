// By Hash Table Method

class Solution {
public:
    int totalNumbers(vector<int>&digits) {
        int n=digits.size();
        vector<int>mp(10,0);                  // Hash Table bna lo

        // Har digit ki frequency store karo
        for(int i=0;i<n;i++){
            mp[digits[i]]++;
        }
        int res=0;                            // Answer ko 0 se shuru karo

        // 3 digit number ke liye first digit 1-9 hona chahiye
        for(int i=1;i<=9;i++){
            if(mp[i]==0){
                continue;
            }
            mp[i]--;                          // First digit use kardo

            // Middle digit 0-9 kuch bhi ho sakta hai
            for(int j=0;j<=9;j++){
                if(mp[j]==0){
                    continue;
                }
                mp[j]--;                      // Middle digit use kardo

                // Last digit even hona chahiye
                for(int k=0;k<=8;k+=2){
                    if(mp[k]>0){
                        res++;                 // Ek valid number mil gaya
                    }
                }
                mp[j]++;                      // Middle digit wapas daaldo
            }
            mp[i]++;                          // First digit wapas daaldo
        }
        return res;
    }
};