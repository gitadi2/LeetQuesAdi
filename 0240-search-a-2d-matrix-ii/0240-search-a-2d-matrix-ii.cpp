class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();        // No. of the Rows
        int m=matrix[0].size();     // Npo. if the Columns

        int row=n-1;                // Last Row ko lelia 
        int col=0;                  // Fist Column ko lelia 

        while(row>=0 && col<m){
            if(matrix[row][col]==target){
                return true;
            }

            if(matrix[row][col]<target){
                // agar y condition hold karta hai tab Column ko Eliminate kardo 
                col++;
            }
            else{
                // Agara ye Condition hold Karta hai tab Row Ko eliminate Kardo
                row--; 
            }
        }
        return false;           // If Nothing comes 
    }
};