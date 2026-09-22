class Solution {
public:
// Comaparator leleo 
bool static comp(vector<int>&a,vector<int>&b){
    if(a[1]<b[1]){
        return true;
    }
    else{
        return false;
    }
}

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();        // No. of the Intervals k liye 

        // Edge Case 
        if(n==0){
            return 0;          // Agar Interval size hai hoi nhi toh zero return kardo 
        }        

        sort(intervals.begin(),intervals.end(),comp);     // Siort a/c to the End Time 
        int cnt=1;          // count of the intervals taken and shuru mei 1 toh hoga hi 
        int lastEndTime=intervals[0][1];         // End Time of the 1st interval

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastEndTime){
                // Agar esa hua toh can be taken
                cnt++;
                lastEndTime=intervals[i][1];
            }
        }
        return n-cnt;                 // Y humey Min no. of Intervals leney wla bolega 
    }
};