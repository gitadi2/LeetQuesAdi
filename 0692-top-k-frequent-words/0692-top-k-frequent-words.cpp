class Solution {
public:
struct cmp{
    bool operator()(const pair<int,string>&a, const pair<int,string>&b){
        if(a.first!=b.first){
            return a.first>b.first;         // Min Heap of the First 
        }
        return b.second>a.second;           // Max heap on the Second one 
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        
        // Priority Queue Declaration
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq; 

        // Hashmap Declaration
        unordered_map<string,int> mp;

        // Loop for the Hashmap
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }  

        for(auto i:mp){
            string words=i.first;
            int freq=i.second;

            pair<int,string> curr={freq,words};

            if(pq.size()<k){
                pq.push(curr);
                continue;
            }

            if(curr.first<pq.top().first){
                continue;
            }

            if(curr.first==pq.top().first && curr.second>pq.top().second){
                continue;
            }
            pq.pop();
            pq.push(curr);
        }

        vector<string> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(),res.end());

        return res; 
    }
};