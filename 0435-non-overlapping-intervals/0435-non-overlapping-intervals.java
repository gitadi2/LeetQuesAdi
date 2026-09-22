class Solution {
    public int eraseOverlapIntervals(int[][]intervals) {
        int n=intervals.length;        // No. of the Intervals k liye

        // Edge Case
        if(n==0) {
            return 0;                  // Agar Interval size hai hi nhi toh zero return kardo
        }

        Arrays.sort(intervals,(a,b)->{
            if(a[1]<b[1]) {
                return -1;
            }
            else if(a[1]>b[1]) {
                return 1;
            }
            else {
                return 0;
            }
        });                            // Sort a/c to the End Time

        int cnt=1;                     // count of the intervals taken and shuru mei 1 toh hoga hi
        int lastEndTime=intervals[0][1]; // End Time of the 1st interval

        for(int i=1;i<n;i++) {
            if(intervals[i][0]>=lastEndTime) {
                // Agar aisa hua toh can be taken
                cnt++;
                lastEndTime=intervals[i][1];
            }
        }
        return n-cnt;                  // Y humey Min no. of Intervals leney wala bolega
    }
}