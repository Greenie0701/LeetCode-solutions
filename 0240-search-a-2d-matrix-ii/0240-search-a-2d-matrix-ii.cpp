class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Assign the row and column values for traversal
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            // Check if the elements in that row is smaller than target, if yes target may not be found
            // This is because all row are in decreasing and col wise increasing
            else if(matrix[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};