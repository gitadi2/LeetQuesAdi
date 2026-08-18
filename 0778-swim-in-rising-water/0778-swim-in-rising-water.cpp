class Solution {
public:
// Directions K liye Array Bna Lo 
int x[4]={1,-1,0,0};                     // Along the X axis 
int y[4]={0,0,1,-1};                      // Along the Y axis 

// Check karlo ki matrix k ander hi arha hai ki nhi 
bool valid(int i,int j, int n, int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    // Otherwise 
    return true;
}

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();                  // No. of the Rows 
        int m=grid[0].size();               // No. of the Columns 

        // resultant k liye 2D matrix Bna Lo 
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));     

        // Min Heap bna Lo (pairs Form Wla)  {time,{row,col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        res[0][0]=grid[0][0];                // Phelea Wla Ka time jo hai whi mark karlo 
        pq.push({grid[0][0],{0,0}});          // Min Heap mein Push Kardo 

        while(!pq.empty()){
            // jab tak Min Heap pura Khali nhi hojta Hai 
            pair<int,pair<int,int>>p=pq.top();                  // Top mein hi aya hoga 
            pq.pop();                                           // Pop karlo wrna inf loop mein chla jaega 

            int dist=p.first;                                // Distance Store karlega 
            int row=p.second.first;
            int col=p.second.second;

            if(dist>res[row][col]){
                // Agar Dist current dist se jyada ata Hai , so skip and continue 
                continue;
            }

            if(row==n-1 && col==m-1){
                // Destination has Been Reached hai 
                return dist;
            }

            for(int k=0;k<4;k++){
                // 4 directions k along Neighbours dekhlo 
                int r=row+x[k];
                int c=col+y[k];

                if(valid(r,c,n,m)){
                    int newWt=max(grid[r][c],dist);
                    // relaxation Kardo 
                    if(newWt<res[r][c]){
                        res[r][c]=newWt;
                        pq.push({newWt,{r,c}});                // Update karkey Min Heap mein push kardo
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};