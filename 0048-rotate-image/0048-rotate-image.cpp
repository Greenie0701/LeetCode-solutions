class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size()-1;
        while(left<right){
            int top = left;
            int bottom = right;
            for(int i =0; i<right-left; i++){
                // store the top left 
                int topleft = matrix[top][left+i];
                matrix[top][left+i] = matrix[bottom-i][left];
                matrix[bottom-i][left] = matrix[bottom][right-i];
                matrix[bottom][right-i] = matrix[top+i][right];
                matrix[top+i][right] = topleft;
            }
            left++;
            right--;
        }
    }
};