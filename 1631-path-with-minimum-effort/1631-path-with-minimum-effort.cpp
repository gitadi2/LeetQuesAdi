class Solution {
public:
// Directions K liye Array Bna Lo 
int x[4]={1,-1,0,0};                      // Along the X axis 
int y[4]={0,0,1,-1};                        // Along the Y Axis 

bool valid(int i,int j,int n,int m){
    // Matrix k ander hi hai ki nhi chk karo 
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    // Otherwise 
    return true;
}

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();                             // No. of the Rows 
        int m=heights[0].size();                          // No. of the Columns 

        // 2D Matrix Bna lo of resultant 
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));       // 2D array resultant 

        // Dijikstra Alogrithm start karlo 
        // Min Heap bna Lo 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        res[0][0]=0;                         // Start src se src tak res mei 0 aaega 
        pq.push({0,{0,0}});                  // Heap Mei push Kardo ..heap of type({dist,{row,col}})

        while(!pq.empty()){
            // Jab Tak Heap khali nhi hojata tab tak process kartey raho 
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();

            int dist=p.first;
            int row=p.second.first;
            int col=p.second.second;

            if(dist>res[row][col]){
                // Skip and Continue kyunki purana value hai 
                continue;
            }

            for(int k=0;k<4;k++){
                int r=row+x[k];           // Sarey directions mei x k along neighbour dekhlo 
                int c=col+y[k];            // Sarey Directions Mein y k along neighbour Dekhlo 

                if(!valid(r,c,n,m)){
                    // Skip and Continue
                    continue;
                }
                // Agar Esa Nhi hai 
                int absDiff=abs(heights[row][col]-heights[r][c]);   // Absolute diff from src to curr wla 

                int newWt=max(absDiff,dist);
                if(newWt<res[r][c]){
                    // Relaxation Kardo 
                    res[r][c]=newWt;         // Update 
                    pq.push({newWt,{r,c}});        // Push onto the Heap 
                }
            }
        } 
        return res[n-1][m-1];
    }
};