class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            if(!grid[i][0]){
                for(int j=0; j<n; j++){
                    grid[i][j]^=1;
                }
            }
        }
        for(int j=1; j<n; j++){
            int ones=0;
            for(int i=0; i<m; i++){
                if(grid[i][j])ones++;
            }
            if(ones<(m-ones)){
                for(int i=0; i<m; i++){
                    grid[i][j] ^= 1;
                }
            }
        }
        int scores=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                scores+=(grid[i][j]<<(n-j-1));
            }
        }
        return scores;
    }
};