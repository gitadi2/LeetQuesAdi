class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;          // Ek resultant 2D array bna lo shuru mei empty hai 
        int i=0;         // Travaersal k liye use hoga 
        int n=intervals.size();              // Given no. of the Intervals 

        // Left Segment 
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);         // Resulatant arry mei pair ko hi lelo 
            i++;          // Increment karlo i ko
        } 
        // Middle Segment: Overlapping intervals k liye 
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);       // Start wla mIn lena hoga 
            newInterval[1]=max(newInterval[1],intervals[i][1]);       // End wla Max lena hoga 
            i++;
        }
        res.push_back(newInterval);

        // Right Segment k liye 
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;            // Array 2D wla of Resultant milega 
    }
};