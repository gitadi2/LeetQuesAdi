// By DP + Binary Search Method

class Solution {
public:
    struct Node{
        long long score;
        vector<int>ids;
    };

    // Lexicographically smaller array check
    bool smaller(vector<int>&a,vector<int>&b){
        for(int i=0;i<a.size() && i<b.size();i++){
            if(a[i]!=b[i]){
                return a[i]<b[i];
            }
        }
        return a.size()<b.size();
    }

    // Better answer check karo
    Node better(Node a,Node b){
        if(a.score>b.score){
            return a;
        }
        if(b.score>a.score){
            return b;
        }
        if(smaller(a.ids,b.ids)){
            return a;
        }
        return b;
    }

    vector<int> maximumWeight(vector<vector<int>>&intervals) {
        int n=intervals.size();
        // Interval ke saath original index bhi store karo
        vector<array<int,4>>v;

        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],intervals[i][1],intervals[i][2],i});
        }

        // Ending point ke according sort karo
        sort(v.begin(),v.end(),[](auto&a,auto&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });
        // Previous non-overlapping interval find karo
        vector<int>prev(n);

        for(int i=0;i<n;i++){
            int low=0;
            int high=i-1;
            int ans=-1;
            // Current interval ke start se strictly chhota end chahiye
            while(low<=high){
                int mid=(low+high)/2;
                if(v[mid][1]<v[i][0]){
                    ans=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            prev[i]=ans;
        }
        // dp[i][j] = first i intervals mein se at most j intervals ka best answer
        vector<vector<Node>>dp(n+1,vector<Node>(5));

        // DP fill karo
        for(int i=1;i<=n;i++){
            for(int j=1;j<=4;j++){
                // Current interval ko skip karo
                Node skip=dp[i-1][j];
                // Current interval ko take karo
                Node take;
                take.score=v[i-1][2];

                if(prev[i-1]!=-1){
                    take.score+=dp[prev[i-1]+1][j-1].score;
                    take.ids=dp[prev[i-1]+1][j-1].ids;
                }

                // Current interval ka original index add karo
                take.ids.push_back(v[i-1][3]);
                // Indices ko ascending order mein rakho
                sort(take.ids.begin(),take.ids.end());
                // Skip aur take mein better answer choose karo
                dp[i][j]=better(skip,take);
            }
        }
        return dp[n][4].ids;
    }
};