class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int res=-1;                 // If sometimes no peak comes ; auto ans can be generated

        while(low<=high){
            int guess=(low+high)/2;

            // If there is an upward slope
            if(arr[guess]<arr[guess+1]){
                // to avi bhi chadhai hai to upr jana hoga or monotonically right mein jna hoga
                low=guess+1;
            }
            // If there is a downward slope
            else{
                // arr[guess]>arr[guess+1]
                // to avi humey dhalan m jna hoga or monotonically left mein jana hoga 
                res=guess;            // Jo mila hai woh ho skat h ans to store karlo 
                high=guess-1;         // Peechey kardo first oocurence of the Peak k liye
            }
        }
        return res;                   // Peak ka index return kardo ; agr nhi h to auto -1 aaega
    }
};