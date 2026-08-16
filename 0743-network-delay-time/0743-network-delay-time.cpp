class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Graph representation : Adjacency List bana lo 
        vector<vector<pair<int,int>>>adj(n+1);       // Adjacency list of no of V erices K size Ka 
        for(int i=0;i<times.size();i++){
            int src=times[i][0];                  // source 
            int dest=times[i][1];                 // Destination
            int wt=times[i][2];                  // Edge Weight 

            // Ab jod Lo :For a Directed Graph
            adj[src].push_back({dest,wt});
        }
        
        // Min Haeap Banalo 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        // Dist wla array banalo 
        vector<int>dist(n+1,INT_MAX);        // No. of Verices  ka array with Infinity at every posn

        dist[k]=0;          // k to k tak ka dist 0 hai 
        pq.push({0,k});     // Src yni ki k ko uskey dist ke sath push kardo heap mein 

        while(!pq.empty()){
            // Jab Tak Heap khali nhi hojata hai Tab tak process mein Rakhey raho 
            pair<int,int>p=pq.top();               // Min heap ka hi pair mein sabsey min dist wla top banega
            pq.pop();                              // Top ko pop karna hota hai 

            int d=p.first;                         // Y baki logo ka dist banega 
            int node=p.second;                     // Jo Node hai baki ka apart from src 

            if(d>dist[node]){
                // Skip and Continue
                continue;
            }
            for(int j=0;j<adj[node].size();j++){
                int neighbour=adj[node][j].first;
                int w=adj[node][j].second;

                if(d+w<dist[neighbour]){
                    // Relaxation Karloo 
                    dist[neighbour]=d+w;
                    pq.push({d+w,neighbour});               // QHeap mein push kardo 
                }
            }
        }
        int res=0;                                         // Ab min dist ka max kitna aya woh ans hai ,start mei 0 

        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;                // Impossible Node hai , unreachable 
            }
            res=max(res,dist[i]);
        }
        return res;
    }
};