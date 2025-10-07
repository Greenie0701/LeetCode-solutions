class Solution {
public:
    bool searchTarget(vector<int>& matrix, int target){
        // Simply perform the binary search in the 1-D array
        int low = 0;
        int high = matrix.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid]==target){
                return true;
            }
            else if(matrix[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            if(searchTarget(matrix[i],target)){
                return true;
            }else{
                continue;
            }
        }
        return false;
    }
};