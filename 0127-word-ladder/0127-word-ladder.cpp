class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        // Agar String given hai and humey dekhna hai ki array m hai ki nhi hai 
        unordered_map<string,int>mp;                  // hashMap bna lo of string and int types 

        // Pheley hashMap mei daldoo 
        for(int i=0;i<n;i++){
            mp[wordList[i]]=1;           // Hashmap mei daldo 
        }

        if(mp.find(endWord)==mp.end()){ 
            // Agar end Word hi nhi hai in the Hashmap
            return 0;          // return 0 kardo 
            
        }

        queue<pair<string,int>>q;           // BFS karna hai toh Queue bnalo 
        q.push({beginWord,1});                   // Queue mei begin and val 1 se shuru karo 
        mp.erase(beginWord);               // HashMap se usko hta do like woh visit hogya ahi 

        while(!q.empty()){
            // Jab Tak queue Empty nhi hojta ahi tab tak process kartey raho 
            pair<string,int>p=q.front();
            q.pop();
            string s=p.first;
            int val=p.second;

            if(s==endWord){
                return val;               // Agar String End word wla hi hai toh return karo val 
            }
            // Agar nhi hai 
            for(int i=0;i<s.size();i++){
                char c=s[i];                // Jo bhi hai char wise lelo 
                for(int j=97;j<=122;j++){
                    if(c==j){
                        // whi wla char mila toh skip kro mat lo 
                        continue;
                    }
                    // Otherwise 
                    s[i]=j;              // ek type of char ko dekho , usko out of 25 left wley se badli kro
                    if(mp.find(s)!=mp.end()){
                        // agar jo badli wla hai hi Hahmap mei yni arry mei bhi 
                        q.push({s,val+1});
                        mp.erase(s);
                    }
                }
                s[i]=c;         // ek type ke 25 badli and mila toh honey k bad wapis same charpr aao 
            }
        }
        // Agar kuch karney k baad bhi nhi mila 
        return 0; 
    }
};