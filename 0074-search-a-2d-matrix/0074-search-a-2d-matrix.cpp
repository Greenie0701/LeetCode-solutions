class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int low = 0;
        int high = m*n-1;
        // Perform the binary search to obtain the value
        while(low<=high){
            int mid = low + (high-low)/2;
            int col = mid%m;
            int row = mid/m;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};