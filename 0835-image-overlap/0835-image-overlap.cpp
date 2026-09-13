class Solution {
public:
    int largestOverlap(vector<vector<int>>&img1,vector<vector<int>>&img2) {
        int n=img1.size();

        vector<pair<int,int>>a;             // Image 1 ke 1s ke coordinates
        vector<pair<int,int>>b;             // Image 2 ke 1s ke coordinates

        // Image 1 ke saare 1s store karo
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    a.push_back({i,j});
                }
            }
        }
        // Image 2 ke saare 1s store karo
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img2[i][j]==1){
                    b.push_back({i,j});
                }
            }
        }
        // Har possible shift ki frequency store karo
        map<pair<int,int>,int>mp;

        int res=0;                          // Maximum overlap

        // Image 1 ke har 1 ko Image 2 ke har 1 ke saath match karo
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                int x=b[j].first-a[i].first;
                int y=b[j].second-a[i].second;

                // Is shift ki frequency badha do
                mp[{x,y}]++;

                // Maximum overlap update karo
                res=max(res,mp[{x,y}]);
            }
        }
        return res;
    }
};