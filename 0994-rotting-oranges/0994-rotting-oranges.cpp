class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rotten(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    rotten[i][j]=2;
                    q.push({{i, j},0});
                }
            }
        }
        int time = 0;
        vector<int> drow = {1, -1, 0, 0}; 
        vector<int> dcol = {0, 0, 1, -1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(t, time);
            for(int i=0; i<4; i++){
                int r = x+drow[i];
                int c = y+dcol[i];
                if(r>=0&&r<m&&c>=0&&c<n&&!rotten[r][c]&&grid[r][c]==1){
                    q.push({{r, c}, t+1});
                    rotten[r][c]=2;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1&&rotten[i][j]!=2)return -1;
            }
        }
        return time;
    }
};