class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size() - 1;
        // Iterate untill left crosses right
        while(left<right){
            // Use for loop to perform the rotation at exact index 
            // Basically right - left number of rotation
            for(int i=0; i<right-left;i++){
                // Top and Bottom would be same as bottom
                int top     = left;
                int bottom  = right;
                // Store the top most element
                int topleft = matrix[top][left+i];
                // Move bottom left element to top left
                matrix[top][left+i] = matrix[bottom-i][left];
                // Move bottom right to bottom left
                matrix[bottom-i][left] = matrix[bottom][right-i];
                // Move top right to bottom left
                matrix[bottom][right-i] = matrix[top+i][right];
                // Move top left to top right
                matrix[top+i][right] = topleft;
            }
            // Increment left and decrement right pointer
            left++;
            right--;
        }
    }
};