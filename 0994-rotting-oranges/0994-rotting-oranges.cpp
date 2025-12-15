class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // Visited array is just to mark them they are rotten already
        vector<vector<int>> visited(row, vector<int>(col, 0));
        // Queue ds to track {x, y} and time taken to rotten the grid
        queue<pair<pair<int, int>, int>> q;
        // Time taken initially is zero
        int time = 0; 
        // Bush all rotten fruits initially in the Grid
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    visited[i][j]=2;
                }
            }
        }
        // Perform BFS to rotten all oranges
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;
            time = max(t, time);
            vector<int> drow = {0, 0, 1, -1};
            vector<int> dcol = {1, -1, 0, 0};
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0&&nrow<row&&ncol>=0&&ncol<col&&visited[nrow][ncol]!=2&&grid[nrow][ncol]==1){
                    q.push({{nrow, ncol},t+1});
                    visited[nrow][ncol]=2;
                }
            }
        }
        // Check the visited array if all oranges are rotten 
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1&&visited[i][j]!=2){
                    return -1;
                }
            }
        }

        return time;
    }
};