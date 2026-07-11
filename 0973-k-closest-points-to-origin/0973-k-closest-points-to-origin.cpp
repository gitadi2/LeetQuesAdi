class Solution {
public:
struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        if(a.first!=b.first){
            // Min wla fisrst lena hai 
            return b.first>a.first;
        }
        // Min wala hi second lemna hogaaa
        return b.second>a.second;
    }
};

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();

        // Priority Queue Declaration
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;

        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];

            int dist=x*x+y*y;

            pair<int,int>curr={dist,i};           // Iss trh se raka jaega 

            if(pq.size()<k){
                // Still in the Process ; toh randomly push k elements and move fwd
                pq.push(curr);
                continue;
            }

            if(curr.first>=pq.top().first){
                // skip and move fwd
                continue;
            }
            pq.pop();
            pq.push(curr);
        }

        vector<vector<int>> res;                // Taking a 2D array of the Resultant 

        while(!pq.empty()){
            res.push_back(points[pq.top().second]);          // Res 2D array mein second wley ko push kardo
            pq.pop();                                // ab pop kardo 
        }
        return res;                                // Resultant 2D array return kardo 
    }
};