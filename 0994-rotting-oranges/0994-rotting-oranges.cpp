class Solution {
public:
    bool isvalid(int row, int col, int m, int n){
        return(row>=0&&row<m&&col>=0&&col<n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        queue<pair<int, pair<int, int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({0, {i, j}});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int t = val.first;
            int row = val.second.first;
            int col = val.second.second;
            time = max(t, time);
            for(int i=0; i<4; i++){
                int r = row+drow[i];
                int c = col+dcol[i];
                if(isvalid(r, c, m, n)){
                    if(grid[r][c]==1){
                        grid[r][c]=0;
                        q.push({t+1, {r, c}});
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};