class Solution {
public:
int fun(int m,int n,int guess){
    int count=0; 

    for(int i=1;i<=m;i++){
        count=count+min(n,guess/i);      // Har Row mein guess se chotey ya equal elements kitney hain 
    }
    return count;
}

    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n; 
        int res=-1;

        while(low<=high){
            int guess=(low+high)/2;

            int ans=fun(m,n,guess);        // Guess se lesser ya equla Elements ka count

            if(ans<k){
                low=guess+1;        // Right mein jao 
            }
            else{
                res=guess;        // Store Karlo 
                high=guess-1;     // Left mein chley jao 
            }
        }
        return res;
    }
};