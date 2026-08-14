class Solution {
public:
bool valid(int i,int j,int n,int m){
    // Matrix k ander hai ki nhi dekhlo 
    if(i<0 || i>=n || j<0 || j>=m){
        // Yani ki matrix k bahar hai , so return False
        return false;
    }
    return true;    // Otherwise 
}

// Directions K liye Array bna lo 
int x[4]={1,-1,0,0};                     // Along the X coordinate 
int y[4]={0,0,1,-1};                     // Along the Y coordinate 

void dfs(vector<vector<char>>&board,int i,int j,int n,int m){
    board[i][j]='#';            // Jo jo Visited karkey Safe hai O mei unkko # se replace kardo 

    // All 4 directiuons mei dekhlo 
    for(int k=0;k<4;k++){
        int row=i+x[k];                  // Alongf the Row 
        int col=j+y[k];                  // Along the Column

        if(valid(row,col,n,m) && board[row][col]=='O'){
            // oh DFS chala lo 
            dfs(board,row,col,n,m);
        }
    }
    return;
}

    void solve(vector<vector<char>>& board) {
        int n=board.size();                        // No. of the Rows 
        int m=board[0].size();                     // No. of the Columns

        // Ab Boundry se shuru karigey toh sarey dekhlo 

        for(int j=0;j<m;j++){
            // First Row k liye 
            if(board[0][j]=='O'){
                dfs(board,0,j,n,m);
            }
        }

        for(int j=0;j<m;j++){
            // last row K liye 
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j,n,m);
            }
        }

        for(int i=0;i<n;i++){
            // First Col k liye 
            if(board[i][0]=='O'){
                dfs(board,i,0,n,m);
            }
        }

        for(int i=0;i<n;i++){
            // Last Column k liye 
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#'){
                    // Agar Sab kuch khatm hua jo Hash Bachey unko 0 se replace jardo 
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';         // Agar 0 ko kha lia ya pheley se X hai toh whi sahi 
                }
            }
        }
        return;
    }
};