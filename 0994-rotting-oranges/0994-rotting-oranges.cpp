class Solution {
public:
// Directions k liye Function  Bna Lo
int x[4]={-1,1,0,0};                     // Along the X Coordinate
int y[4]={0,0,-1,1};                     // Along the Y Coordinate 

bool valid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        // Agar y sab hai toh yni orange Grid k bahar rakh gya ahi 
        return false;
    }
    return true;      // Otherwise 
}

    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();                    // No. of ther Rows 
       int m=grid[0].size();                 // Noof the Columns 
       
       // Multi Source BFS use hoga toh queue Bna loo 
       queue<pair<int,int>>q;                 // Queue of pair type for coordinate storing 

       int fresh=0;                           // Fresh oranges intit 0 se kro 
       int time=0;                            // Time bhi 0 se init kro 

       // Queue k liye Loop bna looo 
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             if(grid[i][j]==2){
                // Grid mei already Rooten Orange dekho  
                q.push({i,j});                      // Already Rotten orange hai toh Push kro cordi ko 
                grid[i][j]=0;                      // Push krney k baad empty man lo for visited hai purpose
            }
            else if(grid[i][j]==1){
                // Agar Fresh Orange Hai 
                fresh++;                              // Fresh ka count badha dooo 
            }
        }
       }
       while(!q.empty() && fresh>0){
        time++;                          // Time Ko agey Badha Do 

        int s=q.size();

        while(s--){
            // Queue ka size nikal lo or parelly agr Oranges Rooten aye Uskey Liye 
            pair<int,int>p=q.front();                // Rotten Wla Orange Queue k Front mei rahega 
            q.pop();

            // Rowe and Col all the $ directions Mei Lelo 
            int r=p.first;
            int c=p.second;

            for(int k=0;k<4;k++){
                int row=r+x[k];
                int col=c+y[k];

                if(valid(row,col,n,m) && grid[row][col]==1){
                    // Yani agar  valid hai and fresh orange hai 
                    q.push({row,col});
                    grid[row][col]=0;            //Puish kardo and usko empty man lo 
                    fresh--;                    // Fresh ka Count ghata Do 
                }
            }
        }
       }
       if(fresh>0){
        // sab kuch karleney k baad Bhi agar fresh ka count 0 se bada hai 
        return -1;
       }
       return time;             // Return kardo tim,e agar esa nhi hai 
    }
};