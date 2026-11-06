class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        int q=queries.size();

        sort(logs.begin(),logs.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });

        vector<pair<int,int>>v;
        for(int i=0;i<q;i++){
            v.push_back({queries[i],i});
        }

        sort(v.begin(),v.end());

        vector<int>cnt(n+1,0);
        vector<int>res(q,0);

        int l=0,r=0,active=0;

        for(int i=0;i<q;i++){
            int t=v[i].first;
            int idx=v[i].second;

            while(r<m && logs[r][1]<=t){
                int server=logs[r][0];
                if(cnt[server]==0) active++;
                cnt[server]++;
                r++;
            }
            while(l<r && logs[l][1]<t-x){
                int server=logs[l][0];
                cnt[server]--;
                if(cnt[server]==0) active--;
                l++;
            }
            res[idx]=n-active;
        }
        return res;
    }
};