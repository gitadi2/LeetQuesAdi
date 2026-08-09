class Solution {
public:
// direction Arrays bna Lo 
int x[4]={-1,1,0,0};                     // Along the X corrdinate 
int y[4]={0,0,-1,1};                      // Along the y-Coordinate 

bool valid(int i, int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        // agar inmey se kch bhi hai ; troh ap matrix se bahar ho 
        return false;
    }
    // Otherwise
    return true;
}

// Ab DFS ka fun bna lo 
void dfs(vector<vector<char>>&grid,int n,int m,int i, int j,vector<vector<bool>>&visited){
    // phele jah par pahuncha land mein ; woh visited hoga 
    visited[i][j]=1;

    for(int k=0;k<4;k++){
        int row=i+x[k];                 // Row of all 4 directions 
        int col=j+y[k];                 // Col of all the 4 directions 

        if(valid(row,col,n,m) && grid[row][col]=='1' && visited[row][col]==false){
            // Ahar valid hai ; land hai and non visited bhi hai ; toh ofc dfs ko chal lo 
            dfs(grid,n,m,row,col,visited);
        }
    }
    return;
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();                       // No. of the Rows
        int m=grid[0].size();                       // No. of the Columns 

        int res=0;                             // Resultant jo ki shuru mei 0 hoga 
        int i;
        int j;

        // 2D matrix bool wla bna lo (mtlb ki Visited wla)
        vector<vector<bool>>visited(n,vector<bool>(m,false));                  // Visited wla array 2D wla 
        
        // Explore karega ; Block se Block compa hoga 
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    // Land bhi hai and Not Visited bhi hai 
                    dfs(grid,n,m,i,j,visited);

                    res++;                           // Res me dal dena hota hai 
                }
            }
        }
        return res;   
    }
};