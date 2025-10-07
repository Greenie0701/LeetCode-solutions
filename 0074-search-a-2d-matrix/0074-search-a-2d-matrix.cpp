class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Initialise low and high value
        int n = matrix.size();
        int m = matrix[0].size();
        // We can assume that we flatten the array and initialise the low and high index
        int low = 0;
        int high = m+n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            // Get the mid index in 2D matrix
            int row = mid/m;
            int col = mid%m;
            // Now cross check with the mid value with target
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};