// DFS + Ancestor Tracking + Reverse Traversal

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>g(n);

        // Build the original tree
        for(int i=1;i<n;i++){
            g[parent[i]].push_back(i);
        }
        vector<int>newParent=parent;
        vector<int>last(26,-1);
        vector<int>prev(n,-1);
        vector<int>order;

        // Iterative DFS
        vector<pair<int,bool>>st;
        st.push_back({0,false});

        while(!st.empty()){
            auto [u,exit]=st.back();
            st.pop_back();
            int idx=s[u]-'a';

            if(exit){
                last[idx]=prev[u];
            }
            else{
                prev[u]=last[idx];

                if(last[idx]!=-1){
                    newParent[u]=last[idx];
                }
                last[idx]=u;
                order.push_back(u);

                st.push_back({u,true});

                for(int i=(int)g[u].size()-1;i>=0;i--){
                    st.push_back({g[u][i],false});
                }
            }
        }
        // Calculate subtree sizes
        vector<int>res(n,1);

        for(int i=n-1;i>0;i--){
            int u=order[i];
            res[newParent[u]]+=res[u];
        }
        return res;
    }
};