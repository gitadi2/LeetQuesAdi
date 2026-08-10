class Solution {
public:
void dfs(vector<vector<int>>&isConnected,int n,int node,vector<bool>&visited){
    visited[node]=1;                // Jo bhi node first aaega toh visited mei dalo 

    for(int i=0;i<n;i++){
        if(isConnected[node][i]==1 && visited[i]==false){
            // agar direct connectrion  hai and ab tak dusra node visit nhi hua hai '
            dfs(isConnected,n,i,visited);       // Toh dfs ko chal alo 
        }
    }
    return;
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();                             // No. Of the cities
        int res=0;                                    // Resulatant jo shuru mei khjali hoga 

        vector<bool>visited(n,false);                // Visited ka 2D matrix form of n size and sarey galat

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && visited[j]==false){
                    // Agar Direct Conn hai and visited nHi hai  
                    dfs(isConnected,n,j,visited);

                    res++;                     // Ek pura Proivince Mil jaega 
                }
            }
        }
        return res;
    }
};