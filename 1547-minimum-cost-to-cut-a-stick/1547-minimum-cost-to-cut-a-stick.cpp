// By the Tabulation Method In DP

class Solution {
public:
    int minCost(int n, vector<int>& c) {
        vector<int>cuts;                      // Cuts ka Arry bna lo 

        cuts.push_back(0);                     // Nye cuts arry mein 0 as start dalo 
        
        // Cuts Array ko pura daldo 
        for(int i=0;i<c.size();i++){
            cuts.push_back(c[i]);
        }

        cuts.push_back(n);                      // Length of the Cuts array ko last cell mein daldo 

        sort(cuts.begin(),cuts.end());         // Sort Kardo 
        int s=cuts.size();                     // Cuts wley Array ka size Including the New elements

        vector<vector<int>>dp(s,vector<int>(s,0));    // 2D Array(matrix) odf DP bna lo 

        for(int i=s-2;i>=1;i--){
            for(int j=i;j<=s-2;j++){
                int res=INT_MAX;               // res ko INT_MAX set kardo 

                for(int k=i;k<=j;k++){
                    // Matlab ki i and j ke khin beech se kata @'k'
                    int cost=cuts[j+1]-cuts[i-1];
                    int r=cost+dp[i][k-1]+dp[k+1][j];        // Temp ans store karlo 

                    res=min(res,r);                         // Update kardo         
                }
                dp[i][j]=res;                      
            }
        }
        return dp[1][s-2];                            
    }
};