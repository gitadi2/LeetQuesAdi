class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&a,const pair<int,int>&b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second>b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        // Priority Queue dec common
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        // Hashmap Declaration
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;             // Elements ko traverse karkey hashmap mein daal do
        }

        for(auto i:mp){
            int element=i.first;
            int freq=i.second;

            pair<int,int> curr={freq,element};      // HashMap mei curr element ese aaega

            if(pq.size()<k){
                pq.push(curr);      // Randomly elements ko daal do in that format in the Priority Queue
                continue;
            }

            if(curr.first<pq.top().first){
                // Skip and move fwd
                continue;
            }

            pq.pop();             // Pop the Top one ofc
            pq.push(curr);
        }

        // For the Final Ans Array
        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};