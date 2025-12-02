class Solution {
public:
    int findmax(vector<vector<int>>& mat, int col){
        int maxi = INT_MIN;
        int row = -1;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][col]>maxi){
                maxi = mat[i][col];
                row = i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int rowmax = findmax(mat, mid);

            int left = mid-1<0?-1:mat[rowmax][mid-1];
            int right = mid+1>=mat[0].size()?-1:mat[rowmax][mid+1];

            if(left<mat[rowmax][mid]&&right<mat[rowmax][mid]){
                return{rowmax, mid};
            }
            else if(left>mat[rowmax][mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return{-1,-1};
    }
};