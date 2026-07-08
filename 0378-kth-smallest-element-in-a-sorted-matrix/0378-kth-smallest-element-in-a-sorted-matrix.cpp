class Solution {
public:
int fun(vector<vector<int>>&matrix, int n, int guess){
    int row=n-1;
    int col=0;
    int count=0;

    while(row>=0 && col<n){
        if(matrix[row][col]<=guess){
            count=count+row+1;               // Left Over Elements jo hai + row ka ek or
            col++;                           // Column ko Shift Kardo 
        }
        else{
            row--;                          // Row Ko hi Eliminate Kardo 
        }
    }
    return count;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();                         // No. of the Rows and No. Of the cols

        int low=matrix[0][0];
        int high=matrix[n-1][n-1];

        int res=-1;

        while(low<=high){
            int guess=(low+high)/2;

            int ans=fun(matrix,n,guess);

            if(ans<k){
                low=guess+1;          // Right mei agey badh jao
            }
            else{
                res=guess;          // Store karlo cuxz ho skta hai 
                high=guess-1;      // Left mein chley jao 
            }
        }
        return res;
    }
};