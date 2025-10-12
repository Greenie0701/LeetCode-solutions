class Solution {
public:
    int maxindex(vector<vector<int>>& mat, int mid){
        int maxi = mat[0][mid];
        int index = 0;
        for(int i=1; i<mat.size(); i++){
            if(mat[i][mid]>maxi){
                maxi = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int n = mat.size();
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int maxrowindex = maxindex(mat, mid);
            int right = mid+1 >= m ? -1:mat[maxrowindex][mid+1];
            int left = mid-1 < 0 ? -1:mat[maxrowindex][mid-1];
            if(left<mat[maxrowindex][mid] && right< mat[maxrowindex][mid]){
                return {maxrowindex, mid};
            }
            else if(left>mat[maxrowindex][mid]){
                high = mid-1;
            }
            else if(right>mat[maxrowindex][mid]){
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};