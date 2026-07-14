class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();     // kisi ka bhiu size lelo dono same hai 
        vector<pair<int,int>>proj;     // Pair leloo

        for(int i=0;i<n;i++){
            proj.push_back({capital[i],profits[i]});       // iss structure mei dal ke karlo pair 
        }
        
        sort(proj.begin(),proj.end());               // ascending mei sort hojaega 

        priority_queue<int> pq;                // Max Heap 

        int idx=0;                             // Pair wley array ke liye index ptr

        while(k--){
            while(idx<n){
                if(proj[idx].first>w){
                    // Nahi aaskata hai 
                    break;
                }
                // Agar aaskata hai tab 
                pq.push(proj[idx].second);        // Profits k hisab se store karlo 
                idx++;              // Inc kartey chloo
            }

            // Edge case 
            if(pq.empty()){
                return w;
            }

            w=w+pq.top();          // Max profit wley ko lekey add kardo w mei 
            pq.pop();              // Us pair ko heasp se hta do 
        }
        return w;             // Final max Capital 
    }
};