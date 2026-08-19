class Solution {
public:

    long long minInitialStrength(vector<int>&monsters,vector<vector<int>>&boosts){
        int n=monsters.size();                         // No. of monsters

        // Difference Array for boosts
        vector<long long>diff(n+1,0);

        for(int i=0;i<boosts.size();i++){
            int l=boosts[i][0];                        // Left
            int r=boosts[i][1];                        // Right
            int v=boosts[i][2];                       // Boost Value

            // Range Update
            diff[l]+=v;
            diff[r+1]-=v;
        }

        long long bonus=0;                             // Current bonus
        long long prefix=0;                            // Previous monsters ki total strength
        long long res=0;                               // Minimum initial strength

        for(int i=0;i<n;i++){
            // Current index ka bonus nikal lo
            bonus+=diff[i];

            if(bonus<monsters[i]){
                // Current strength ki requirement
                long long need=prefix+monsters[i]-bonus;
                res=max(res,need);
            }
            // Current monster defeat hone ke baad uski strength consume hogi
            prefix+=monsters[i];
        }
        return res;
    }
};