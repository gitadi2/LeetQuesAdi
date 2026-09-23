class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        vector<int>start(n);       // Start ka arry of size "n" bna lo 
        vector<int>en(n);          // End ka Array of size "n" bna lo 

        for(int i=0;i<n;i++){
            start[i]=intervals[i][0];      // Start Time in the start array
            en[i]=intervals[i][1];         // End Time in the en Array 
        }

        sort(start.begin(),start.end());      // Sort the Start Array 
        sort(en.begin(),en.end());            // Sort the End Array 

        int i=0;       // Start Array ka ptr
        int j=0;       // End Array ka ptr 

        int cnt=0;     // Groups Count karega 
        int maxCnt=0;  // Max Count among that grp lega 

        while(i<n && j<n){
            if(start[i]<=en[j]){
                // Agr start wla end se chotta ya equal hai 
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxCnt=max(maxCnt,cnt);
        }
        return maxCnt;
    }
};