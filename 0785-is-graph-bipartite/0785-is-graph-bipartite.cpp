class Solution {
public:
bool res=true;           // Global Variable resultant k liye , shuru mein true manlo

void dfs(vector<vector<int>>&graph,int node,int c,vector<int>&color){
    color[node]=c;           // Koi Bhi Color from 1 or 0 jo ki shuru mei start k liye use kia gya ho 

    for(int j=0;j<graph[node].size();j++){
        int neighbour=graph[node][j];                 // Us Node ka Har Ek neighbour Dekhlooo 
        if(color[neighbour]!=-1 && color[neighbour]==c){
            // Agar Aleady Colured Node Hai and previous Node wla hi color hai present Node Mein 
            res=false;            // Toh Baptartite Nhi hai 
        }
        if(color[neighbour]==-1){
            // agar Woh Node Colred Nhi hai, toh opp of prev node ka color kardo and dfs bhi chla lo  
            dfs(graph,neighbour,1-c,color);
        }
    }
    return;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();                   // No of the Vertices of the Graph 
        vector<int>color(V,-1);             // Colors k liye Array bna Lo of size V and -1 all 

        // Multi Graph DFS ho skta hai 
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                // Agar Non Volred hai shuru mei hi 
                dfs(graph,i,0,color);                   // Shuru mei 0 wley Color kardunga 
            }
        }
        return res;
    }
};