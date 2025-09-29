class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralmatrix;
        // Initialise top, bottom, left, right pointers
        int left  = 0;
        int right = matrix[0].size();   
        int top   = 0;
        int bottom = matrix.size();     
        // Iterate until left doesnot crosses right and 
        // top does not crosses bottom
        while(left < right && top < bottom){
            // Iterate from top left to top right and append to answer
            for(int i = left; i < right; i++){
                spiralmatrix.push_back(matrix[top][i]);
            }
            top++;
            // Iterate from right top to right bottom
            for(int i = top; i < bottom; i++){
                spiralmatrix.push_back(matrix[i][right - 1]); 
            }
            right--;
            // Check whether given matrix is one-dimensional or column matrix
            // break the loop
            if (left >= right || top >= bottom){ 
                break;
            }
            // Iterate from right bottom to left bottom
            for(int i = right - 1; i >= left; i--){  
                spiralmatrix.push_back(matrix[bottom - 1][i]); 
            }
            bottom--;
            // Iterate from left bottom to left top
            for(int i = bottom - 1; i >= top; i--){  
                spiralmatrix.push_back(matrix[i][left]); 
            }
            left++;
        }
        return spiralmatrix;
    }
};
