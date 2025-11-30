class Solution {
public:

    int findmaxrow(vector<vector<int>>& mat, int col){
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

            int row = findmaxrow(mat, mid);

            int left = mid-1<0?-1:mat[row][mid-1];
            int right = mid+1>high?-1:mat[row][mid+1];

            if(left<mat[row][mid]&&right<mat[row][mid]){
                return{row, mid};
            }
            else if(left>mat[row][mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return{-1,-1};
    }
};