// Brute Force Method of Problem Solving

class Solution {
    public int candy(int[]ratings) {
        int n=ratings.length;
        int[]left=new int[n];                 // Left Array bna lo of size n
        int[]right=new int[n];                // Right Array bhi bna lo of size n

        left[0]=1;                            // Left Array ke shuru wley ko 1 hi milega
        right[n-1]=1;                         // Right Array ke last wley ko bhi 1 hi milega

        // Left Neighbour Comparison k liye Traversing kardo
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) {
                left[i]=left[i-1]+1;          // Agar bda hogya than prev toh count badha do by 1
            }
            else{
                // Agar esa kch hua nhi
                left[i]=1;
            }
        }
        // Right Neighbour Comparison k liye bhi Traversing kardo
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) {
                right[i]=right[i+1]+1;        // Agar bda hogya than nxt toh count ko badha do by 1
            }
            else{
                // Agar esa kch bhi nhi hai
                right[i]=1;
            }
        }
        
        int sum=0;                            // Var for sum
        for(int i=0;i<n;i++){
            sum+=Math.max(left[i],right[i]);  // Max of left and Right ko lekey add kardo
        }
        return sum;                           // Min no. of Reqd. Candies
    }
}