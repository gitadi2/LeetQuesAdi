class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();    // No. of the Rows
        int m=matrix[0].size();  // No. of the Cols

        int low=0;
        int high=m*n-1;

        while(low<=high){
            int guess=(low+high)/2;

            int row=guess/m;               // Row niakl lo 
            int col=guess%m;                // Column nikal lo 

            if(matrix[row][col]==target){
                return true;
            }
            if(matrix[row][col]<target){
                low=guess+1;             // Right cheley jao
            }
            else{
                high=guess-1;           // Left chle aao 
            }
        }
        return false;  
    }
};