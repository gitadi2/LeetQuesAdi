class Solution {
public:
    int minCost(string source,string target,vector<vector<string>>&rules,vector<int>&costs){
        int n=source.size();                         // Length of source

        if(n!=target.size()){
            // Agar dono ki length same nhi hai
            return -1;
        }

        long long INF=1e18;                          // Infinity

        vector<long long>dp(n+1,INF);                // DP array
        dp[n]=0;                                     // Last position par cost 0

        // Rules ko store karne ke liye
        vector<tuple<string,string,int,long long>>pro;

        for(int i=0;i<rules.size();i++){
            string pat=rules[i][0];                  // Pattern
            string rep=rules[i][1];                  // Replacement
            int L=pat.size();                        // Length of pattern

            // Cost + pattern mein '*' ki count
            long long c=costs[i]+count(pat.begin(),pat.end(),'*');
            pro.push_back({pat,rep,L,c});
        }

        // Right se left DP
        for(int i=n-1;i>=0;i--){
            // Agar current character already same hai
            if(source[i]==target[i]){

                dp[i]=dp[i+1];
            }

            // Har rule ko check karo
            for(int j=0;j<pro.size();j++){
                string pat=get<0>(pro[j]);            // Pattern
                string rep=get<1>(pro[j]);            // Replacement
                int L=get<2>(pro[j]);                 // Length
                long long cost=get<3>(pro[j]);        // Cost

                // Agar rule string se bahar chala jayega
                if(i+L>n){
                    continue;
                }

                bool ok=true;

                // Source ke saath pattern match karo
                for(int k=0;k<L;k++){

                    if(pat[k]!='*' && pat[k]!=source[i+k]){
                        // Pattern match nhi hua
                        ok=false;
                        break;
                    }
                }

                if(!ok){
                    continue;
                }

                // Replacement target ke saath match hona chahiye
                for(int k=0;k<L;k++){
                    if(rep[k]!=target[i+k]){
                        // Replacement target ke equal nhi hai
                        ok=false;
                        break;
                    }
                }
                if(!ok){
                    continue;
                }
                // Relaxation / DP update
                dp[i]=min(dp[i],cost+dp[i+L]);
            }
        }
        // Agar target banana possible nhi hua
        if(dp[0]==INF){
            return -1;
        }
        return dp[0];
    }
};