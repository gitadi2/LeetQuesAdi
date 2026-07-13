class Solution {
public:
struct cmp{
    bool operator()(const pair<int,char>&a, const pair<int,char>&b){
        if(a.first!=b.first){
            return b.first>a.first;              // Max Heap on the First one 
        }
        return b.second>a.second;              // Max Heap on the Second one 
    }
};

    string reorganizeString(string s) {
        int n=s.size();

        // HashMap Declaration 
        unordered_map<char,int>mp;

        // Loop for the HasshMap 
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        // priority Queue Dec
        priority_queue<pair<int,char>,vector<pair<int,char>>, cmp> pq;

        // Inserting the elements along with their freq onto the hashmap 
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        string res="";                 // Intially Strinf wil be Empty and this will be the resulatant string
        int slot=0;                         // Slot too empty

        while(!pq.empty()){
            // Jab tak pq Empoty nahi hai 
            pair<int,char>p1=pq.top();            // Heap k top element ko dekho 
            pq.pop();                             // Usi element ko pop krk htao 

            if(slot==0 || res[slot-1]!=p1.second){
                // matlab agar result empty hai OR element diff hai to dall sktey hai 
                res.push_back(p1.second);       // Diff hai toh daal do

                slot++;                 // Slot ko bda do 

                p1.first--;             // p1 k first wla ko kaam kardo 
                if(p1.first>0){
                    pq.push(p1);  // agar p1 ka first 0 se bda hai tabhi woh exist krta ha toh daal do heap m 
                }
                continue;
            }

            // same char aagya adj posn par 
            if(pq.empty()){
                return ""; 
            }

            pair<int,char>p2=pq.top();       //agar phela same hai toh heap top second se decide hioga 
            pq.pop();                        // haeap top wlwey ko hi htao 

            res.push_back(p2.second);

            slot++;

            p2.first--;

            pq.push(p1);                    // Phela chr wapis heap mein push kardo 

            if(p2.first>0){
                pq.push(p2);
            }
        }
        return res;  
    }
};