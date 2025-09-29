class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Row size is same as matrix size
        int rows = matrix.size();
        // Column size is same as size of elements in a row
        int cols = matrix[0].size();
        // Handle the first column seperately to avoid overlap
        int col0 = 1;

        // Iterate through the matrix
        for(int i=0; i<rows; i++){
            // Any row, check the first column is zero if yes, change col0
            if(matrix[i][0]==0)col0=0;
            for(int j=1; j<cols; j++){
                // If any of the element in the matrix is zero, mark it as 
                // zero in the corresponding first row and column 
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        // Iterate from last element in the matrix
        for(int i=rows-1;i>=0; i--){
            // Skip first column in every row, but iterate through all col
            for(int j=cols-1; j>=1; j--){
                // Check both 0th col and 0th row matrix is
                // If yes make current element is zero
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
            // Handle first column seperately for every row
            if(col0==0){
                matrix[i][0]=0;
            }
        }
    }
};
