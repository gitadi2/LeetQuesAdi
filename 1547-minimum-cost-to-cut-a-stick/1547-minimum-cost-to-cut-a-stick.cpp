// By Memoization Method in DP

class Solution {
public:
int fun(vector<int>&cuts,int i,int j, vector<vector<int>>&dp){
    // base Case: agar Out of Range hai 
    if(i>j){
        return 0;
    }
    // Dekhlo ki DP Matrix mein present hai ki nhi 
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int res=INT_MAX;                         // Res ko set kardo at max 
    // Ab i and j range k beech kahin se bhi kaat sktey hai lests say @'k'
    for(int k=i;k<=j;k++){
        int cost=cuts[j+1]-cuts[i-1];
        int r=cost+fun(cuts,i,k-1,dp)+fun(cuts,k+1,j,dp);    // Temp ans store karlo from costs jo mila hai 
        res=min(res,r);                                     // Res ko upadate kardo 
    }
    return dp[i][j]=res;
}

    int minCost(int n, vector<int>& c) {
        vector<int>cuts;                        // Cuts k arry mei agey peechey add karna hai tabhi ese lo 
        cuts.push_back(0);                      // Array k shuru mei y daldo 

        // Ab arry k elements ko hi daldo 
        for(int i=0;i<c.size();i++){
            cuts.push_back(c[i]);   
        }

        // Ab Array k end mein bhi length of the stick daldo 
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());              // Sort karlo cuts array ko 
        int s=cuts.size();                          // Cuts Array ka size with new added elemnts 

        vector<vector<int>>dp(s,vector<int>(s,-1));     // 2D array(matrix) of size s*s bna lo with -1 ele

        // Recursive Function Call kardo 
        return fun(cuts,1,s-2,dp);
    }
};