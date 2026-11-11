// Ordered Set + Min Heap 

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();

        set<int>available;

        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>>busy;

        vector<int>cnt(k,0);

        for(int i=0;i<k;i++){
            available.insert(i);
        }
        for(int i=0;i<n;i++){
            // Free all servers whose tasks are completed
            while(!busy.empty() && busy.top().first<=arrival[i]){
                int idx=busy.top().second;
                busy.pop();
                available.insert(idx);
            }
            // If all servers are busy, drop the request
            if(available.empty()){
                continue;
            }
            // Find the next available server
            int idx=i%k;
            auto it=available.lower_bound(idx);

            if(it==available.end()){
                it=available.begin();
            }
            int server=*it;
            available.erase(it);
            cnt[server]++;

            // Mark server as busy
            busy.push({(long long)arrival[i]+load[i],server});
        }
        int maxi=*max_element(cnt.begin(),cnt.end());

        vector<int>res;

        for(int i=0;i<k;i++){
            if(cnt[i]==maxi){
                res.push_back(i);
            }
        }
        return res;
    }
};