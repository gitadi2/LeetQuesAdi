class Solution {
public:

    // Directions Array bna lo
    int x[4]={1,-1,0,0};                         // Along the X coordinate
    int y[4]={0,0,1,-1};                         // Along the Y coordinate

    bool valid(int i,int j,int n,int m){
        // Matrix ke ander hai ki nhi dekhlo
        if(i<0 || i>=n || j<0 || j>=m){
            // Agar Matrix ke bahar hai
            return false;
        }

        return true;
    }

    int minMoves(vector<string>& classroom, int energy) {

        int n=classroom.size();                  // No. of Rows
        int m=classroom[0].size();               // No. of Columns

        int cnt=0;                               // Litter ka count

        int sr=0;
        int sc=0;

        // Start Position and Litter count nikal lo
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(classroom[i][j]=='S'){
                    // Starting position mil gayi
                    sr=i;
                    sc=j;
                }

                if(classroom[i][j]=='L'){
                    // Litter mila
                    cnt++;
                }
            }
        }

        // Agar Litter hi nhi hai
        if(cnt==0){
            return 0;
        }

        // State:
        // row, column, energy, collected litter ka mask
        queue<tuple<int,int,int,int,int>>q;

        // visited[row][col][energy][mask]
        int states=1<<cnt;

        vector<vector<vector<vector<bool>>>>visited(n,vector<vector<vector<bool>>>(m,vector<vector<bool>>(energy+1,vector<bool>(states,false))));
        // Start mein koi litter collect nhi hua
        int mask=0;
        q.push({sr,sc,energy,mask,0});
        visited[sr][sc][energy][mask]=true;

        while(!q.empty()){
            // Queue se current state nikal lo
            auto [r,c,e,mask,dist]=q.front();
            q.pop();

            // Agar saare litter collect ho gaye
            if(mask==states-1){
                return dist;
            }

            // 4 directions mein move karo
            for(int k=0;k<4;k++){
                int row=r+x[k];
                int col=c+y[k];
                // Agar valid position nhi hai
                if(!valid(row,col,n,m)){
                    continue;
                }
                // Wall hai
                if(classroom[row][col]=='X'){
                    continue;
                }
                // Har move mein energy 1 decrease hogi
                int newEnergy=e-1;
                // Energy khatam ho gayi
                if(newEnergy<0){
                    continue;
                }
                int newMask=mask;
                // Agar Litter mila
                if(classroom[row][col]=='L'){
                    // Litter ka index nikalna padega
                    int id=0;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++){
                            if(classroom[i][j]=='L'){
                                if(i==row && j==col){
                                    newMask=newMask|(1<<id);
                                }

                                id++;
                            }
                        }
                    }
                }
                // Agar Energy refill ho sakti hai
                if(classroom[row][col]=='R'){
                    newEnergy=energy;
                }
                // Agar ye state pehle visit nhi hui
                if(visited[row][col][newEnergy][newMask]==false){
                    visited[row][col][newEnergy][newMask]=true;
                    q.push({
                        row,
                        col,
                        newEnergy,
                        newMask,
                        dist+1
                    });
                }
            }
        }
        // Saara litter collect nhi kar paye
        return -1;
    }
};