// Brute Force Method of Problem Solving 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>left(n);                 // Left Array bna lo of size n 
        vector<int>right(n);                // Right Array bhi bna lo of size n

        left[0]=1;                   // Left Arry  ke shuru wley ko 1 hi milega 
        right[n-1]=1;                // Right Array k shuru wley ko bhi 1 hi milega 

        // Left Neighbour Comparison k liye Traversing kardo 
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;          // Agar bda hogya than prev toh count badha do by 1 
            }
            else{
                // Agar esa kch hua nhi 
                left[i]=1;
            }
        }
        // Right Neighbour Comparison k liye bhi TRaversing kasrdo 
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;       // Agar bda hogya than nxt toh count ko badha do by 1
            }
            else{
                // Agar esa kch bhi nhi hai 
                right[i]=1;
            }
        }
        int sum=0;               // var for sum 
        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);   // Max of left and Righ ko lekey add kardo 
        }
        return sum;        // Min no. of Reqd. Candies 
    }
};