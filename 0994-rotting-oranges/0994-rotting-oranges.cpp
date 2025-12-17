class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> rotten(row, vector<int>(col, 0));
        int time = 0;
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2){
                    rotten[i][j]=2;
                    q.push({{i, j},0});
                }
            }
        }
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        while(!q.empty()){
            auto rot = q.front();
            q.pop();
            int r = rot.first.first;
            int c = rot.first.second;
            int t = rot.second;
            time = max(time, t);
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0&&nrow<row&&ncol>=0&&ncol<col&&rotten[nrow][ncol]!=2&&grid[nrow][ncol]==1){
                    rotten[nrow][ncol] =2;
                    q.push({{nrow, ncol}, t+1});
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1&&rotten[i][j]!=2){
                    return -1;
                }
            }
        }
        return time;
    }
};