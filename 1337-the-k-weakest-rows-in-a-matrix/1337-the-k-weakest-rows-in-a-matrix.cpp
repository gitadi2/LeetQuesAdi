class Solution {
public:
struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        if(a.first!=b.first){
            // Max wla first lena hai 
            return b.first>a.first;
        }
        // Max wala hi second lena hogaaa
        return b.second>a.second;
    }
};

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();

        // Priority Queue Declaration
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        for(int i=0;i<n;i++){
            int soldier=0;

            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    soldier++;
                }
            }

            pair<int,int> curr={soldier,i};           // Iss trh se raka jaega 

            if(pq.size()<k){
                // Still in the Process ; toh randomly push k elements and move fwd
                pq.push(curr);
                continue;
            }

            if(curr.first>pq.top().first){
                // skip and move fwd
                continue;
            }

            if(curr.first==pq.top().first && curr.second>=pq.top().second){
                // Same Soldiers par bada Row Index hai toh skip
                continue;
            }

            pq.pop();
            pq.push(curr);
        }

        vector<int> res;                // Taking an Array of the Resultant 

        while(!pq.empty()){
            res.push_back(pq.top().second);          // Res Array mein second wley ko push kardo
            pq.pop();                                // ab pop kardo 
        }

        reverse(res.begin(),res.end());              // Weakest se Strongest Order mein chahiye

        return res;                                  // Resultant Array return kardo 
    }
};