// DFS Approach

class Solution {
public:
    int countIslands(vector<vector<int>>& grid,int k) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;

        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};

        // Saare cells ko traverse karo
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // Agar land mila
                if(grid[i][j]>0){
                    long long sum=0;

                    stack<pair<int,int>>st;
                    st.push({i,j});

                    // Visited mark karo
                    sum+=grid[i][j];
                    grid[i][j]=0;

                    // DFS traversal
                    while(!st.empty()){
                        pair<int,int>p=st.top();
                        st.pop();
                        int r=p.first;
                        int c=p.second;

                        // 4 directions mein check karo
                        for(int a=0;a<4;a++){
                            int row=r+x[a];
                            int col=c+y[a];
                            if(row>=0 && row<m && col>=0 && col<n && grid[row][col]>0){
                                sum+=grid[row][col];
                                st.push({row,col});
                                // Visited mark karo
                                grid[row][col]=0;
                            }
                        }
                    }
                    // Island ka sum k se divisible hai ya nahi
                    if(sum%k==0){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};