class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second<b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;

        for(auto word:words){
            mp[word]++;                          // Hashmap mein frequency store karo
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;

        for(auto i:mp){
            string word=i.first;
            int freq=i.second;

            pair<int,string> curr={freq,word};

            if(pq.size()<k){
                pq.push(curr);                   // Phele k elements daal do
                continue;
            }

            if(curr.first<pq.top().first){
                continue;                        // Frequency chhoti hai toh skip
            }

            if(curr.first==pq.top().first && curr.second>pq.top().second){
                continue;                        // Lexicographically bada hai toh skip
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