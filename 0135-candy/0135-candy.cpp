// Brute Force Method of Problem Solving  
 
class Solution { 
public: 
    int candy(vector<int>& ratings) { 
        int n=ratings.size(); 
        vector<int>left(n);                 // Left Array bna lo of size n  
        left[0]=1;                   // Left Arry  ke shuru wley ko 1 hi milega  
 
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
        int curr=1;
        int right=1;
        int sum=max(1,left[n-1]);
        // Right Neighbour Comparison k liye bhi TRaversing kasrdo  
        for(int i=n-2;i>=0;i--){ 
            if(ratings[i]>ratings[i+1]){ 
                curr=right+1;       // Agar bda hua toh curr ko badha do by right +1
                right=curr;        // Update kardo 
            } 
            else{ 
                // Agar esa kch bhi nhi hai  
                curr=1; 
                right=1;
            } 
            sum+=max(left[i],curr);
        } 
        return sum;        // Min no. of Reqd. Candies  
    } 
};